from primes import *


def test_prime_low_number():
    assert is_prime(1) == False


def test_prime_prime_number():
    assert is_prime(29)


def test_prime_composite_number():
    assert is_prime(15) == False


def test_sum_of_prime_empty_list():
    assert sum_of_primes([]) == 0


def test_sum_of_prime_mixed_list():
    assert sum_of_primes([2, 3, 4, 11]) == 16
