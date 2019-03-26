#include "Filter.h"
#include "Log.h"

using namespace std;

Filter::Filter(double freq, double q, double range_low, double range_high,
               const string& type) :
        freq_{ freq }, q_{ q }, range_low_{ range_low },
        range_high_{ range_high}, type_{ type } {
    Log(DEBUG) << "Added filter with frequency " << freq << " Q " << q
               << " range [" << range_low << ", " << range_high << "] and type "
               << type << endl;
}

void Filter::initialize(double gain) {
    // Initialize filter
    // TODO
    (void)gain;
}

Response Filter::optimize(Response& response, const Response& target) {
    // Calculate +- x dB before filter
    // TODO
    auto best = response.get_flatness(target);
    (void)best;

    // Go through possible gains
    // TODO: Do this better
    for (auto gain = range_low_; gain <= range_high_; gain += 0.1) {
        initialize(gain);
        response.apply(*this);
    }

    return response;
}

double Filter::get_gain(double freq) const {
    // TODO
    (void)freq;

    return 0;
}