#include "Easing.h"

float EasingCircInOut(float t, float b, float e) {
  if ((t /= 0.5) < 1) return -(e - b) / 2 * (std::sqrt(1 - t * t) - 1) + b;
  t -= 2;
  return (e - b) / 2 * (std::sqrt(1 - t * t) + 1) + b;
}


float EasingBackIn(float t, float b, float e) {
  float s = 1.70158;
  return (e - b) * t * t * ((s + 1) * t - s) + b;
}


float EasingBounceOut(float t, float b, float e) {
  if (t < (1 / 2.75)) {
    return (e - b) * (7.5625 * t * t) + b;
  }
  else if (t < (2 / 2.75)) {
    t -= (1.5 / 2.75);
    return (e - b) * (7.5625 * t * t + 0.75) + b;
  }
  else if (t < (2.5 / 2.75)) {
    t -= (2.25 / 2.75);
    return (e - b) * (7.5625 * t * t + 0.9375) + b;
  }
  else {
    t -= (2.625 / 2.75);
    return (e - b) * (7.5625 * t * t + 0.984375) + b;
  }
}

float EasingBounceIn(float t, float b, float e) {
  return (e - b) - EasingBounceOut(1.0 - t, 0, e - b) + b;
}


float EasingBounceInOut(float t, float b, float e) {
  if (t < 0.5) return EasingBounceIn(t * 2, 0, e - b) * 0.5 + b;
  else         return EasingBounceOut(t * 2 - 1.0, 0, e - b) * 0.5 + (e - b) * 0.5 + b;
}