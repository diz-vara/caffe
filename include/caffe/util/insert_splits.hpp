#ifndef _CAFFE_UTIL_INSERT_SPLITS_HPP_
#define _CAFFE_UTIL_INSERT_SPLITS_HPP_

#include <string>

#include "caffe/proto/caffe_pb.h"

namespace caffe {

// Copy NetParameters with SplitLayers added to replace any shared bottom
// blobs with unique bottom blobs provided by the SplitLayer.
DLL_EXPORT void InsertSplits(const NetParameter& param, NetParameter* param_split);

DLL_EXPORT void ConfigureSplitLayer(const string& layer_name, const string& blob_name,
    const int blob_idx, const int split_count, const float loss_weight,
    LayerParameter* split_layer_param);

DLL_EXPORT string SplitLayerName(const string& layer_name, const string& blob_name,
    const int blob_idx);

DLL_EXPORT string SplitBlobName(const string& layer_name, const string& blob_name,
    const int blob_idx, const int split_idx);

}  // namespace caffe

#endif  // CAFFE_UTIL_INSERT_SPLITS_HPP_
