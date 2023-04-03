// #include "../include/PmergeMe.hpp"

// TEST_CASE("PergeMe constructor with no arguments") {
//     PergeMe pergeMe;
//     CHECK(pergeMe.getInitialVecSequence().empty());
//     CHECK(pergeMe.getSortedVecSequence().empty());
//     CHECK(pergeMe.getInitialSetSequence().empty());
//     CHECK(pergeMe.getSortedSetSequence().empty());
// }

// TEST_CASE("PergeMe constructor with vector argument") {
//     std::vector<int> seq {4, 2, 8, 1, 5};
//     PergeMe pergeMe(seq);
//     CHECK(pergeMe.getInitialVecSequence() == seq);
//     CHECK(pergeMe.getSortedVecSequence() == std::vector<int>{1, 2, 4, 5, 8});
//     CHECK(pergeMe.getInitialSetSequence().empty());
//     CHECK(pergeMe.getSortedSetSequence().empty());
// }

// TEST_CASE("PergeMe constructor with set argument") {
//     std::set<int> seqSet {4, 2, 8, 1, 5};
//     PergeMe pergeMe(seqSet);
//     CHECK(pergeMe.getInitialVecSequence().empty());
//     CHECK(pergeMe.getSortedVecSequence().empty());
//     CHECK(pergeMe.getInitialSetSequence() == seqSet);
//     CHECK(pergeMe.getSortedSetSequence() == std::set<int>{1, 2, 4, 5, 8});
// }

// TEST_CASE("PergeMe setSequence with invalid arguments") {
//     PergeMe pergeMe;
//     int argc = 0;
//     char *argv[] = {};
//     CHECK_THROWS(pergeMe.setSequence(argc, argv));
// }

// TEST_CASE("PergeMe setSequence with valid arguments") {
//     PergeMe pergeMe;
//     int argc = 6;
//     char *argv[] = {"./prog", "4", "2", "8", "1", "5"};
//     pergeMe.setSequence(argc, argv);
//     CHECK(pergeMe.getInitialVecSequence() == std::vector<int>{4, 2, 8, 1, 5});
//     CHECK(pergeMe.getSortedVecSequence() == std::vector<int>{1, 2, 4, 5, 8});
//     CHECK(pergeMe.getInitialSetSequence() == std::set<int>{4, 2, 8, 1, 5});
//     CHECK(pergeMe.getSortedSetSequence() == std::set<int>{1, 2, 4, 5, 8});
// }

// TEST_CASE("PergeMe sortVector") {
//     std::vector<int> seq {4, 2, 8, 1, 5};
//     PergeMe pergeMe(seq);
//     pergeMe.sortVector(seq);
//     CHECK(seq == std::vector<int>{1, 2, 4, 5, 8});
// }

// TEST_CASE("PergeMe sortSet") {
//     std::set<int> seqSet {4, 2, 8, 1, 5};
//     PergeMe pergeMe(seqSet);
//     pergeMe.sortSet(seqSet);
//     CHECK(seqSet == std::set<int>{1, 2, 4, 5, 8});
// }

// // You can add more test cases for other member functions as well
