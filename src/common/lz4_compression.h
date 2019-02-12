// Copyright 2019 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <vector>

#include "common/common_types.h"

namespace Common::Compression {

/**
 * Compresses a source memory region with LZ4 and returns the compressed data in a vector.
 *
 * @param source the uncompressed source memory region.
 * @param source_size the size in bytes of the uncompressed source memory region.
 *
 * @return the compressed data.
 */
std::vector<u8> CompressDataLZ4(const u8* source, std::size_t source_size);

/**
 * Utilizes the LZ4 subalgorithm LZ4HC with the specified compression level. Higher compression
 * levels result in a smaller compressed size, but require more CPU time for compression. The
 * compression level has almost no impact on decompression speed. Data compressed with LZ4HC can
 * also be decompressed with the default LZ4 decompression.
 *
 * @param source the uncompressed source memory region.
 * @param source_size the size in bytes of the uncompressed source memory region.
 * @param compression_level the used compression level. Should be between 3 and 12.
 *
 * @return the compressed data.
 */
std::vector<u8> CompressDataLZ4HC(const u8* source, std::size_t source_size, s32 compression_level);

/**
 * Utilizes the LZ4 subalgorithm LZ4HC with the highest possible compression level.
 *
 * @param source the uncompressed source memory region.
 * @param source_size the size in bytes of the uncompressed source memory region.
 *
 * @return the compressed data.
 */
std::vector<u8> CompressDataLZ4HCMax(const u8* source, std::size_t source_size);

/**
 * Decompresses a source memory region with LZ4 and returns the uncompressed data in a vector.
 *
 * @param compressed the compressed source memory region.
 * @param uncompressed_size the size in bytes of the uncompressed data.
 *
 * @return the decompressed data.
 */
std::vector<u8> DecompressDataLZ4(const std::vector<u8>& compressed, std::size_t uncompressed_size);

} // namespace Common::Compression