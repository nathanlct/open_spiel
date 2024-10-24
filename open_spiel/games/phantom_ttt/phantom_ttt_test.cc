// Copyright 2019 DeepMind Technologies Limited
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "open_spiel/spiel.h"
#include "open_spiel/tests/basic_tests.h"

namespace open_spiel {
namespace phantom_ttt {
namespace {

namespace testing = open_spiel::testing;

void BasicPhantomTTTTests() {
  testing::LoadGameTest("phantom_ttt");
  testing::NoChanceOutcomesTest(*LoadGame("phantom_ttt"));
  testing::RandomSimTest(*LoadGame("phantom_ttt"), 100);
  testing::RandomSimTestWithUndo(*LoadGame("phantom_ttt"), 1);
}

void AbruptAndClassicalPhantomTTTTests() {
  testing::LoadGameTest("phantom_ttt(gameversion=classical)");
  testing::LoadGameTest("phantom_ttt(gameversion=abrupt)");
  testing::NoChanceOutcomesTest(*LoadGame("phantom_ttt(gameversion=classical)"));
  testing::NoChanceOutcomesTest(*LoadGame("phantom_ttt(gameversion=abrupt)"));
}

}  // namespace
}  // namespace phantom_ttt
}  // namespace open_spiel

int main(int argc, char** argv) {
  open_spiel::phantom_ttt::BasicPhantomTTTTests();
  open_spiel::phantom_ttt::AbruptAndClassicalPhantomTTTTests();
}
