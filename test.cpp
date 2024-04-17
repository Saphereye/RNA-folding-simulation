#include "rna_folding.cpp"

template <typename T>
inline int assert_equal(T a, T b, std::string test_name) {
    if (a != b) {
        std::cerr << "==============================" << std::endl;
        std::cerr << "Test failed (" << test_name << ")" << std::endl;
        std::cerr << "LHS: " << a << "\nRHS: " << b << std::endl;
        std::cerr << "==============================" << std::endl;
        return 1;
    }

    std::cerr << "Test passed (" << test_name << ")" << std::endl;
    return 0;
}

int main() {
    assert_equal(rna_score("GGGAAAUCC", 0), 3, "Test RNA score 1");
    assert_equal(rna_score("GGUCCAC", 0), 2, "Test RNA score 2");
    assert_equal(rna_score("GGGAAAUCCGGAACC", 0), 5, "Test RNA score 3");
    assert_equal(rna_score("GGGAAAUCCGGAACCGG", 0), 5, "Test RNA score 4");
    assert_equal(rna_score("GGUAGC", 0), 2, "Test RNA score 5");

    std::string rna_sequence = "GGGAAAUCC";
    std::vector<std::pair<int, int>> fold;

    int score = rna_score(rna_sequence);
    traceback(create_matrix(rna_sequence, 0), rna_sequence, fold, 0,
              rna_sequence.size() - 1);

    std::string dot_notation = dot_write(rna_sequence, fold);

    std::cout << "Score: " << score << std::endl;
    std::cout << rna_sequence << std::endl;
    std::cout << dot_notation << std::endl;

    return 0;
    return 0;
}