#include<stdio.h>
#include "number.h"
#include "ir_utility.h"

long get_task();
void run_task(long num_term, double* term, double* rate, long task_flag);

int main(void)
{
    long nTerm = 20;
    long task_flag = 0;
    double term[] = { 0.002739726,0.252054795,0.501369863,0.753424658,1.005479452,1.501369863,2.005479452,3.010958904,4.008219178,5.008219178,6.008219178,7.008219178,8.008219178,9.019178082,10.0109589,12.0109589,15.01643836,20.02191781,25.03561644,30.02465753 };
    double rate[] = { 0.036098215,0.03770441,0.038653575,0.039029734,0.039155685,0.03893001,0.038650828,0.038037416,0.037835382,0.037628573,0.037499704,0.03742338,0.03742969,0.037405569,0.037409742,0.037476437,0.03745011,0.036260804,0.034461684,0.033068879 };

    while ((task_flag = get_task()) != 0)
    {
        run_task(nTerm, term, rate, task_flag);
    }

    return 0;
}

long get_task()
{
    long task_num;
    printf("0: Exit\n1: Zero Rate\n2: Disocunt Factor\n3: Forward Rate\n");
    printf("What Do You Want?: ");
    task_num = get_num();

    return task_num;
}

void run_task(long num_term, double* term, double* rate, long task_flag)
{
    long days1, days2;
    long error_sign = 0;
    double result = 0.0;

    switch (task_flag)
    {
    case 1:
    case 2:
        printf("Input First Days: ");
        days1 = get_num();
        if (days1 < 0)error_sign = -1;
        break;
    case 3:
        printf("Input First Days: ");
        days1 = get_num();
        printf("Input Second Days: ");
        days2 = get_num();
        if (days1 < 0 || days2 < 0 || days2 - days1 < 0) error_sign - 1;
        break;
    }

    if (error_sign == -1)
    {
        printf("Wrong Input!!!\n");
    }
    else {
        switch (task_flag)
        {
        case 1:
            result = calc_zero_rate(num_term, term, rate, (double)days1 / (double)365);
            printf("Result Zero Rate: %.2lf%%\n\n", 100.0 * result);
            break;
        case 2:
            result = calc_discount_factor(num_term, term, rate, (double)days1 / (double)365);
            printf("Result Zero Rate: %.2lf%%\n\n", 100.0 * result);
            break;
        case 3:
            result = calc_forward_rate(num_term, term, rate, (double)days1 / (double)365, (double)days2 / (double)365);
            printf("Result Zero Rate: %.2lf%%\n\n", 100.0 * result); 
            break;
        }
    }
}