#include <iostream>
#include <string>
#define CLOCK 1
#define COUNTER_CLOCK -1
#define GEAR_CNT 4
#define GEAR_LEN 8

using namespace std;

bool gear[GEAR_CNT][GEAR_LEN];
void rotateGear(int gearNum, int dire)
{
    int temp = 0;
    if(dire  == CLOCK)
    {
        temp = gear[gearNum][GEAR_LEN-1];
        for(unsigned int i = GEAR_LEN - 1 ; i > 0 ; i--)
        {
            gear[gearNum][i] = gear[gearNum][i-1];
        }
        gear[gearNum][0] = temp;
    }
    else
    {
        temp = gear[gearNum][0];
        for(unsigned int i = 0 ; i < GEAR_LEN - 1  ; i++)
        {
            gear[gearNum][i] = gear[gearNum][i + 1];
        }
        gear[gearNum][GEAR_LEN-1] = temp;
    }
    
}

int main(void)
{
    int buf = 0;
    string gearStr = "";
    // get initial value of gears
    for(unsigned int i = 0 ; i < GEAR_CNT; i++)
    {
        cin >> gearStr;
        for(unsigned int j = 0; j < GEAR_LEN; j++)
        {
            gear[i][j] = gearStr[j] == '1' ? true : false;
        }
    }

    cin >> buf;
    
    int gearNum = 0;
    int dire = 0;
    // rotate gears
    while(buf-->0)
    {
        int gearRotateAry[GEAR_CNT] = {0,};
        cin >> gearNum >> dire;
        
        gearNum--;

        gearRotateAry[gearNum] = dire;
        
        int rotateGearNum = gearNum;
        int direBuf = dire;
        // check left
        while(rotateGearNum > 0)
        {
            if(gear[rotateGearNum][6] == gear[rotateGearNum-1][2])
            {
                break;
            }
            direBuf *= -1;
            gearRotateAry[rotateGearNum-1] = direBuf;
            rotateGearNum--;
        }        

        rotateGearNum = gearNum;
        direBuf = dire;

        // check right
        while(rotateGearNum < GEAR_CNT -1)
        {
            if(gear[rotateGearNum][2] == gear[rotateGearNum+1][6])
            {
                break;
            }
            direBuf *= -1;
            gearRotateAry[rotateGearNum+1] = direBuf;
            rotateGearNum++;
        }

        for(int i = 0 ; i < GEAR_CNT; i++)
        {
            if(gearRotateAry[i] != 0)
            {
                rotateGear(i,gearRotateAry[i]);
            }
        }
    }

    int totalSum = 0;
    int powNum = 1;
    for(int i = 0; i < GEAR_CNT; i++)
    {
        if(gear[i][0])
        {
            totalSum += powNum;
        }
        powNum *= 2;
    }
    cout << totalSum << endl;
}

