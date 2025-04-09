import pytest
from p646 import findLongestChain


@pytest.mark.parametrize(
    "pairs, expected_length, expected_chain",
    [
        # Happy path tests
        ([], 0, [], "ID01_empty_list"),
        ([[-1, 1], [2, 3], [3, 4]], 2, [0, 2], "ID02_simple_chain"),
        ([[1, 2], [2, 3], [3, 4]], 3, [0, 1, 2], "ID03_linear_chain"),
        ([[5, 24], [15, 25], [27, 40], [50, 60]], 3, [0, 2, 3], "ID04_non_overlapping"),
        ([[1, 2], [7, 8], [4, 5]], 3, [0, 2, 1], "ID05_unsorted_input"),
        # Edge cases
        ([[1, 2]], 1, [0], "ID06_single_pair"),
        ([[1, 2], [2, 3], [3, 4], [1, 5]], 3, [0, 1, 2], "ID07_overlapping_pairs"),
        # Error cases
        # Assuming function should handle non-list inputs gracefully, returning 0, []
        (None, 0, [], "ID08_none_input"),
        ("not a list", 0, [], "ID09_string_input"),
        ([["a", "b"], ["c", "d"]], 0, [], "ID10_non_integer_pairs"),
    ],
)
def test_findLongestChain(pairs, expected_length, expected_chain):
    # Arrange - omitted due to input values provided via test parameters

    # Act
    length, chain = findLongestChain(None, pairs)

    # Assert
    assert (
        length == expected_length
    ), f"Expected chain length {expected_length}, got {length}"
    assert chain == expected_chain, f"Expected chain {expected_chain}, got {chain}"
