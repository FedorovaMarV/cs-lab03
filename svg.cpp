#include "svg.h"


void svg_begin(double width, double height)
{
cout << "<?xml version = '1.0' encoding='UTF-8'?>\n";
cout << "<svg ";
cout << "width='" << width << "' ";
cout << "height='" << height << "' ";
cout << "viewbox='0 0 " << width << " " << height << "' ";
cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_text(double left, double baseline, string text)
{
cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
//<rect x='0' y='0' width='100' height='200' />
cout << "<rect x='" << x << "' y='" << y
<< "' width='" << width << "' height='" << height
<< "' stroke='" << stroke << "' fill='" << fill << "'/>\n";
}

void svg_end()
{
cout << "</svg>\n";
}

const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
const auto RECT_STROKE = "black";
const auto RECT_FILL = "#000000";

void show_histogramm_svg(const vector<size_t>& bins)
{
size_t max_bin = bins[0];
for (size_t bin : bins)
{
if(bin > max_bin)
{
max_bin = bin;
}
}
auto max_bin_width = BLOCK_WIDTH * max_bin;
const auto MAX_BIN_WIDTH = IMAGE_WIDTH - TEXT_WIDTH;

svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

double top = 0;
for(size_t bin : bins)
{
double bin_width = BLOCK_WIDTH * bin;
if(MAX_BIN_WIDTH < max_bin_width)
{
bin_width = static_cast<double>(bin_width) / max_bin_width * MAX_BIN_WIDTH;
}
svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, RECT_STROKE, RECT_FILL);
top += BIN_HEIGHT;
}

svg_end();
}
