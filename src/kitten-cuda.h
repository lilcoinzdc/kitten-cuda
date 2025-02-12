/* kitten
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018-2020 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2020 kitten       <https://github.com/kitten>, <support@kitten.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef kitten_CUDA_H
#define kitten_CUDA_H


#include <cstdint>
#include <cstddef>


#if defined _WIN32 || defined __CYGWIN__
#   define kitten_EXPORT __declspec(dllexport)
#   define kitten_HIDDEN
#else
#   define kitten_EXPORT __attribute__ ((visibility ("default")))
#   define kitten_HIDDEN  __attribute__ ((visibility ("hidden")))
#endif


using nvid_ctx = struct nvid_ctx;


enum Version : uint32_t
{
    ApiVersion,
    DriverVersion,
    RuntimeVersion
};


enum DeviceProperty : uint32_t
{
    DeviceId,
    DeviceAlgorithm,
    DeviceArchMajor,
    DeviceArchMinor,
    DeviceSmx,
    DeviceBlocks,
    DeviceThreads,
    DeviceBFactor,
    DeviceBSleep,
    DeviceClockRate,
    DeviceMemoryClockRate,
    DeviceMemoryTotal,
    DeviceMemoryFree,
    DevicePciBusID,
    DevicePciDeviceID,
    DevicePciDomainID,
    DeviceDatasetHost,
};


#if defined(__cplusplus)
extern "C" {
#endif


kitten_EXPORT bool cnHash(nvid_ctx *ctx, uint32_t startNonce, uint64_t height, uint64_t target, uint32_t *rescount, uint32_t *resnonce);
kitten_EXPORT bool deviceInfo(nvid_ctx *ctx, int32_t blocks, int32_t threads, uint32_t algo, int32_t dataset_host);
kitten_EXPORT bool deviceInit(nvid_ctx *ctx);
kitten_EXPORT bool rxHash(nvid_ctx *ctx, uint32_t startNonce, uint64_t target, uint32_t *rescount, uint32_t *resnonce);
kitten_EXPORT bool rxPrepare(nvid_ctx *ctx, const void *dataset, size_t datasetSize, bool dataset_host, uint32_t batchSize);
kitten_EXPORT bool kawPowHash(nvid_ctx *ctx, uint8_t* job_blob, uint64_t target, uint32_t *rescount, uint32_t *resnonce, uint32_t *skipped_hashes);
kitten_EXPORT bool kawPowPrepare_v2(nvid_ctx *ctx, const void* cache, size_t cache_size, const void* dag_precalc, size_t dag_size, uint32_t height, const uint64_t* dag_sizes);
kitten_EXPORT bool kawPowStopHash(nvid_ctx *ctx);
kitten_EXPORT bool setJob(nvid_ctx *ctx, const void *data, size_t size, uint32_t algo);
kitten_EXPORT const char *deviceName(nvid_ctx *ctx);
kitten_EXPORT const char *lastError(nvid_ctx *ctx);
kitten_EXPORT const char *pluginVersion();
kitten_EXPORT int32_t deviceInt(nvid_ctx *ctx, DeviceProperty property);
kitten_EXPORT nvid_ctx *alloc(uint32_t id, int32_t bfactor, int32_t bsleep);
kitten_EXPORT uint32_t deviceCount();
kitten_EXPORT uint32_t deviceUint(nvid_ctx *ctx, DeviceProperty property);
kitten_EXPORT uint32_t version(Version version);
kitten_EXPORT uint64_t deviceUlong(nvid_ctx *ctx, DeviceProperty property);
kitten_EXPORT void init();
kitten_EXPORT void release(nvid_ctx *ctx);


#if defined(__cplusplus)
}
#endif


#endif /* kitten_CUDA_H */
