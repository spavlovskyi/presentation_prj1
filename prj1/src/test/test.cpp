#include <boost/test/unit_test.hpp>

namespace bu = boost :: unit_test;

namespace {

	BOOST_AUTO_TEST_CASE ( first ) {
		auto i = 1;
		BOOST_TEST ( i == 1 );
	}

	bool init_unit_test ( ) {
		bu :: framework :: master_test_suite ( ).p_name.value = "Main";
		return true;
	}

}

int main ( int argc, char * argv [ ] ) {
	return bu :: unit_test_main (
		& init_unit_test,
		argc,
		argv
	);
}
