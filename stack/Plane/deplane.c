#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


void deplanePassengers(BoardingList* list) 
{
    printf("Deplaning passengers...\n");
 
    while (list->passengerCount > 0) 
    {
 
        // Find first non-empty row
        int row = -1;
        for (int i = 0; i < MAX_ROWS; i++) 
        {
            if (!isEmpty_v1(&list->seatRows[i].ABC) || !isEmpty_v2(&list->seatRows[i].DEF)) 
            {
                row = i;
                break;
            }
        }
        if (row == -1) break;
 
        // Two passes: pass 0 starts LEFT(ABC), pass 1 starts RIGHT(DEF)
        for (int pass = 0; pass < 2; pass++) 
        {
            int currentRow = -1;
            int side = pass;
 
            for (int i = row; i < MAX_ROWS; i++) 
            {
                if (currentRow != -1 && (i - currentRow) < 3)
                    continue;
 
                bool abcHas = !isEmpty_v1(&list->seatRows[i].ABC);
                bool defHas = !isEmpty_v2(&list->seatRows[i].DEF);
 
                if (!abcHas && !defHas) continue; // empty rows
 
                int isLeft = side;
                if (isLeft == 0 && !abcHas) isLeft = 1;
                else if (isLeft == 1 && !defHas) isLeft = 0;
 
                if (isLeft == 0) 
                {
                    while (!isEmpty_v1(&list->seatRows[i].ABC)) 
                    {
                        printf("Deplaning %s from row %d, seat ABC\n", list->seatRows[i].ABC.p[list->seatRows[i].ABC.top].passengerName, i + 1);
                        pop_v1(&list->seatRows[i].ABC);
                        list->passengerCount--;
                    }
                } 
                else 
                {
                    while (!isEmpty_v2(&list->seatRows[i].DEF)) 
                    {
                        printf("Deplaning %s from row %d, seat DEF\n", list->seatRows[i].DEF.p[list->seatRows[i].DEF.top].passengerName, i + 1);
                        pop_v2(&list->seatRows[i].DEF);
                        list->passengerCount--;
                    }
                }
 
                currentRow = i;
                if (isLeft == side) side = 1 - side;
                // switch sides if we deplaned the expected side
            }
        }
    }
 
    printf("All passengers have been deplaned.\n");
}
