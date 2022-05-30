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

double mean(const vector<size_t>& bins) {
    if (bins.size()==0)
        return 0;
    double result;
    double sum=0;
    for (size_t i = 0; i<bins.size(); i++)
    {
        sum = sum + (double)(bins[i]);
    }
    result=sum/((double)(bins.size()));
    return result;
}

vector<size_t> make_histogram(const Input& data)
{
    double min, max;
    find_minmax(data.numbers, min, max);
    vector<size_t> result(data.bin_count);
    for (double number : data.numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * data.bin_count);
        if (bin == data.bin_count) {
            bin--;
        }
        result[bin]++;
    }
    return result;
}

void show_histogram_text(const vector<size_t>& bins)
{
    size_t max_count = 0;
    for (size_t count : bins)
        {
        if (count > max_count)
            max_count = count;
        }

    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins)
    {
        if (bin < 100)
            cout << ' ';

        if (bin < 10)
            cout << ' ';

        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
            {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
            }

        for (size_t i = 0; i < height; i++)
            cout << '*';

        cout << '\n';
    }
}

