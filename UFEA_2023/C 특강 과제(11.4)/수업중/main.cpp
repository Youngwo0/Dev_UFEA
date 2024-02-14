#include <stdio.h>

int get_num();

int main(void)
{
    long nTerm = 20;
    long Days = 0;
    double term[] = { 0.002739726,0.252054795,0.501369863,0.753424658,1.005479452,1.501369863,2.005479452,3.010958904,4.008219178,5.008219178,6.008219178,7.008219178,8.008219178,9.019178082,10.0109589,12.0109589,15.01643836,20.02191781,25.03561644,30.02465753 };
    double rate[] = { 0.036098215,0.03770441,0.038653575,0.039029734,0.039155685,0.03893001,0.038650828,0.038037416,0.037835382,0.037628573,0.037499704,0.03742338,0.03742969,0.037405569,0.037409742,0.037476437,0.03745011,0.036260804,0.034461684,0.033068879 };
    double year_fraction = 35.0;
    double result = 0.0;

    Days = get_num();
    year_fraction = (double) Days / 365.;


    for (long i = 0; i < nTerm; i++)
    {
        if (i == 0)
        {
            if (term[i] >= year_fraction) 
            {
                result = rate[i];
                i = nTerm;
            }
            else if (term[i] <= year_fraction && term[i + 1] >= year_fraction)
            {
                result = rate[i] + (rate[i + 1] - rate[i]) * (year_fraction - term[i]) / (term[i + 1] - term[i]);
                i = nTerm;
            }
        }
        else if(i == nTerm - 1)
        {
            if (term[i] <= year_fraction)
            {
                result = rate[i];
                i = nTerm;
            }
        }
        else
        {
            if (term[i] <= year_fraction && term[i + 1] >= year_fraction)
            {
                result = rate[i] + (rate[i + 1] - rate[i]) * (year_fraction - term[i]) / (term[i + 1] - term[i]);
                i = nTerm;
            }
        }
    }

    printf("Result Zero Rate: %.2lf%%\n", 100.0 * result);
    return 0;
}

int get_num()
{
    int result = 0;
    char temp_char = ' ';
    
    temp_char = getchar();
    while(temp_char != ' ' && temp_char != '\n')
    {
        result *= 10;
        result += temp_char - '0';
        temp_char = getchar();
        
    }
    return result;
}
