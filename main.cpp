#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"

using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 1;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    vector<size_t> bins(bin_count, 0);

    double min, max;
    find_minmax(numbers, min, max);

    double bin_size = (max - min) / bin_count;

    for (double number : numbers)
    {
        bool found = false;
        for (size_t j = 0; j < (bin_count - 1) && (!found); j++)
        {
            auto lo = min + bin_size * j;
            auto hi = min + bin_size * (j + 1);

            if ((lo <= number) && (number < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void show_histogram_text(const vector<size_t>& bins)
{
    size_t max_bins = bins[0];
    for (size_t bin : bins)
    {
        if (bin > max_bins)
        {
            max_bins = bin;
        }
    }

    for (size_t bin : bins)
    {
        double height = bin;

        if (max_bins > MAX_ASTERISK)
        {
            height = MAX_ASTERISK * (static_cast<double>(bin) / max_bins);
        }

        if (bin < 100)
        {
            cout << ' ';
        }

        if (bin < 10)
        {
            cout << ' ';
        }

        cout << bin << "|";

        for (size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}



int main()
{
    //Ввод данных
    size_t number_count;
    cin >> number_count;

    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cin >> bin_count;


    //Расчёт гистограммы
    const auto bins = make_histogram(numbers, bin_count);
    const auto proc = procent (number_count, bins);

    //Вывод данных
    show_histogram_svg(bins, proc);
}
