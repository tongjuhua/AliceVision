
// Copyright (c) 2012, 2013 Pierre MOULON.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "openMVG/robust_estimation/rand_sampling.hpp"
#include "testing/testing.h"
#include <set>

using namespace openMVG;
using namespace openMVG::robust;

// Assert that each time exactly N random number are picked (no repetition)
TEST(UniformSampleTest, NoRepetions) {

  std::vector<std::size_t> samples;
  for (std::size_t total = 1; total < 500; total *= 2)
  { 
    //Size of the data set
    for (std::size_t num_samples = 1; num_samples <= total; num_samples *= 2)
    { //Size of the consensus set
      UniformSample(num_samples, total, &samples);
      std::set<std::size_t> myset;
      for (std::size_t i = 0; i < num_samples; ++i) 
      {
        myset.insert(samples[i]);
        CHECK(samples[i] >= 0);
        CHECK(samples[i] < total);
      }
      CHECK_EQUAL(num_samples, myset.size());
    }
  }
}

TEST(UniformSampleTest, NoRepetionsBeginEnd) {

  std::vector<std::size_t> samples;
  for (std::size_t end = 1; end < 500; end *= 2)
  { 
    //Size of the data set
    for (std::size_t num_samples = 1; num_samples <= end; num_samples *= 2)
    { 
      //Size of the consensus set
      assert((end-num_samples) >= 0);
      const std::size_t begin = end-num_samples;
      UniformSample(begin, end, num_samples, &samples);
      std::set<std::size_t> myset;
      for (std::size_t i = 0; i < num_samples; ++i) 
      {
        myset.insert(samples[i]);
        CHECK(samples[i] >= begin);
        CHECK(samples[i] < end);
      }
      CHECK_EQUAL(num_samples, myset.size());
    }
  }
}

// Assert that each time exactly N random number are picked (no repetition)
TEST(RandomSampleTest, NoRepetions) {

  std::vector<std::size_t> samples;
  for (std::size_t total = 1; total < 500; total *= 2) 
  { 
    //Size of the data set
    for (std::size_t num_samples = 1; num_samples <= total; num_samples *= 2) 
    { 
      //Size of the consensus set
      random_sample(num_samples, total, &samples);
      std::set<std::size_t> myset;
      for (std::size_t i = 0; i < num_samples; ++i)
      {
        myset.insert(samples[i]);
      }
      CHECK_EQUAL(num_samples, myset.size());
    }
  }
}


/* ************************************************************************* */
int main() { TestResult tr; return TestRegistry::runAllTests(tr);}
/* ************************************************************************* */
