//
// Created by qli on 10/08/2021.
//

#include "catch2/catch.hpp"
#include "../containers/vector.h"


TEST_CASE("vector reverse iterator", "[vector_reverse_iterator]")
{
	// data initialization for all sections
	std::vector<int> std_myvector;
	for (int i=0; i<10; i++) std_myvector.push_back(i);
	typedef std::vector<int>::reverse_iterator std_iter_type;

	std_iter_type std_rev_until(std_myvector.begin());
	std_iter_type std_rev_from(std_myvector.end());

	ft::vector<int> ft_myvector;
	for (int i=0; i<10; i++) ft_myvector.push_back(i);
	typedef ft::vector<int>::reverse_iterator ft_iter_type;

	ft_iter_type ft_rev_until(ft_myvector.begin());
	ft_iter_type ft_rev_from(ft_myvector.end());

	SECTION("0. constructor") {
		REQUIRE(*ft_rev_from == *std_rev_from);
		REQUIRE(*ft_rev_until == *std_rev_until);

		while (std_rev_from != std_rev_until)
		{
			REQUIRE(*ft_rev_from == *std_rev_from);
			ft_rev_from++;
			std_rev_from++;
		}
	}

	SECTION("1. base()") {
		// skip the past-the-end element
		std_rev_from++;
		ft_rev_from++;
		while (std_rev_from != std_rev_until)
		{
			REQUIRE(*ft_rev_from.base() == *std_rev_from.base());
			ft_rev_from++;
			std_rev_from++;
		}
	}

	SECTION("2. a*") {
		REQUIRE(*ft_rev_from == *std_rev_from);
		REQUIRE(*ft_rev_until == *std_rev_until);

		while (std_rev_from != std_rev_until)
		{
			REQUIRE(*ft_rev_from == *std_rev_from);
			ft_rev_from++;
			std_rev_from++;
		}
	}

	SECTION("3. a + n") {
		REQUIRE(*(ft_rev_from + 1) == *(std_rev_from + 1));
		REQUIRE(*(ft_rev_from + 3) == *(std_rev_from + 3));
		REQUIRE(*(ft_rev_from + 6) == *(std_rev_from + 6));
		REQUIRE(*(ft_rev_from + 8) == *(std_rev_from + 8));
	}

	SECTION("4. ++a") {
		while (std_rev_from != std_rev_until) {
			REQUIRE(*(ft_rev_from++) == *(std_rev_from++));
		}
	}

	SECTION("4. a++") {
		while (std_rev_from != std_rev_until) {
			REQUIRE(*(++ft_rev_from) == *(++std_rev_from));
		}
	}

	SECTION("5. a += n") {
		ft_rev_from += 1;
		std_rev_from += 1;
		REQUIRE(*ft_rev_from == *std_rev_from);

		ft_rev_from += 4;
		std_rev_from += 4;
		REQUIRE(*ft_rev_from == *std_rev_from);
	}

	SECTION("6. a - n") {
		REQUIRE(*(ft_rev_until - 1) == *(std_rev_until - 1));
		REQUIRE(*(ft_rev_until - 3) == *(std_rev_until - 3));
		REQUIRE(*(ft_rev_until - 6) == *(std_rev_until - 6));
		REQUIRE(*(ft_rev_until - 8) == *(std_rev_until - 8));
	}

	SECTION("7. --a") {
		while (std_rev_from != std_rev_until) {
			REQUIRE(*(ft_rev_until--) == *(std_rev_until--));
		}
	}

	SECTION("7. a--") {
		while (std_rev_from != std_rev_until) {
			REQUIRE(*(--ft_rev_until) == *(--std_rev_until));
		}
	}

	SECTION("8. a -= n") {
		ft_rev_until -= 1;
		std_rev_until -= 1;
		REQUIRE(*ft_rev_until == *std_rev_until);

		ft_rev_until -= 4;
		std_rev_until -= 4;
		REQUIRE(*ft_rev_until == *std_rev_until);
	}

	SECTION("9. a->") {
		// no use case with vector iterator
	}

	SECTION("10. a[n]") {
		REQUIRE(ft_rev_from[1] == std_rev_from[1]);
		REQUIRE(ft_rev_from[3] == std_rev_from[3]);
		REQUIRE(ft_rev_from[6] == std_rev_from[6]);
		REQUIRE(ft_rev_from[8] == std_rev_from[8]);
	}
}