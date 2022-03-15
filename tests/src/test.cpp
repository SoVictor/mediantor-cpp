#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <memory>

#include "gtest/gtest.h"

#include "mediantor.h"

namespace {

using std::cin;
using std::cout;
using std::endl;

namespace fs = std::experimental::filesystem;

std::vector<fs::path> ListFilesInDirectory(const std::string& directory,
                                           const std::string& extension) {
  std::vector<fs::path> file_paths;
  for (const auto& p : fs::directory_iterator(directory)) {
    if (p.path().extension().string() == extension)
      file_paths.push_back(p.path());
  }
  std::sort(file_paths.begin(), file_paths.end());
  return file_paths;
}

}  // namespace

TEST(TestMediantor, TrivialTest) {
  const int n = 3;

  std::unique_ptr<IMediantor> mediantor =
      std::make_unique<MediantorSortedList>();

  mediantor->Insert(1);
  mediantor->Insert(2);
  mediantor->Insert(3);

  EXPECT_EQ(2, mediantor->Take());

  mediantor->Insert(2);
  mediantor->Insert(4);

  EXPECT_EQ(2, mediantor->Take());
}

TEST(TestMediantor, TestOnData) {
  for (int mediantor_type_idx = 0;
       mediantor_type_idx < static_cast<int>(Mediantors::kMediantorsNumber);
       ++mediantor_type_idx) {
    Mediantors mediantor_type = static_cast<Mediantors>(mediantor_type_idx);
    cout << endl;
    cout << "checking " << to_string(mediantor_type) << " ..." << endl;

    for (const fs::path& input_path : ListFilesInDirectory("./data/", ".in")) {
      const std::string test_name = input_path.stem().string();
      cout << "checking test " << test_name << " ..." << endl;

      fs::path ans_path = input_path;
      ans_path.replace_extension(".out");

      std::ifstream input(input_path);
      std::ifstream ans(ans_path);

      int n;
      input >> n;

      std::unique_ptr<IMediantor> mediantor = MakeMediantor(mediantor_type, n);

      for (int i = 0; i < n; i++) {
        int operation;
        input >> operation;
        if (operation) {
          int x;
          input >> x;
          mediantor->Insert(x);
        } else {
          int x;
          ans >> x;
          EXPECT_EQ(x, mediantor->Take());
        }
      }

      EXPECT_TRUE(ans.peek());
    }
  }
}
