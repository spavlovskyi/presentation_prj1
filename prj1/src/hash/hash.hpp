#ifndef SRC_HASH_HASH_HPP_
#define SRC_HASH_HASH_HPP_

#include <cstddef> // otherwise gsl won't pick up std :: byte
#include <gsl/span>

namespace hash {

	using Bytes = gsl :: span < const std :: byte >;

	std :: array < char, 64 > hexSha256 ( Bytes src );

}

#endif /* SRC_HASH_HASH_HPP_ */
