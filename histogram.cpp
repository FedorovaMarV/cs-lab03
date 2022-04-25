#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (numbers.size() == 0)
        return;

    else
    {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers)
        {
            if (number < min)
            {
                min = number;
            }
            if (number > max)
            {
                max = number;
            }
        }
    }
}

vector <size_t> procent (size_t number_count, const vector <size_t> bins)
{
        vector <size_t> x (bins.size());
        for ( size_t i = 0; i < bins.size(); i++ )
        {
            x[i] = static_cast<double> (bins[i]) / number_count * 100;
        }
        return x;
}
