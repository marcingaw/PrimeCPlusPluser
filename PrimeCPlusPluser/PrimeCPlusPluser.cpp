#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>
#include <vector>

int main() {
  std::vector<__int64> found_primes({ 1, 2 });
  __int64 current_value = 3;
  time_t last_tstamp = time(nullptr);

  while (found_primes.size() < 10000000) {
    bool found_divider = false;
    char fmt_time[100];

    for (auto divider : found_primes) {

      if (divider == 1) continue;

      if (divider * divider > current_value) break;

      if (current_value % divider == 0) {
        found_divider = true;
        break;
      }

    }

    if (!found_divider) {
      found_primes.push_back(current_value);

      if (found_primes.size() % 1000000 == 0) {
        time_t now_tstamp = time(nullptr);
        strftime(fmt_time, 99, "%F %T", localtime(&now_tstamp));
        std::cout
          << fmt_time << " - time: " << (now_tstamp - last_tstamp) << " s - "
          << found_primes.size() << " : " << current_value << '\n';
        last_tstamp = now_tstamp;
      }

    }

    current_value += 2;
  }

  return 0;
}
