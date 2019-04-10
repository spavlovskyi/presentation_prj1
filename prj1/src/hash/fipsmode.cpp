#include "fipsmode.hpp"
#include <openssl/crypto.h>
#include <stdexcept>

namespace hash {

	void enableFipsMode ( ) {
		if ( ! FIPS_mode ( ) )
			if ( FIPS_mode_set ( 1 ) != 1 )
				throw std :: runtime_error { "can't set fips mode" };
	}

}
