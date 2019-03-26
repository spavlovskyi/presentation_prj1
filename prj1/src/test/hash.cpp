#include <hash/hash.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE ( hash )

BOOST_AUTO_TEST_CASE ( hello ) {
	static char ref [ ] = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";
	hash :: Bytes src = as_bytes (
		gsl :: make_span ( "hello", 5 )
	);
	auto digest = hash :: hexSha256 ( src );
	std :: string_view sv {
		digest.data ( ),
		digest.size ( )
	};
	BOOST_TEST ( sv == ref );
}

BOOST_AUTO_TEST_SUITE_END ( )
