// ======================================================================================
// Name                :    GeoClasses : Generic Geophysical Flow Modelling Framework
// Description         :    This code pack provides a generic framework for developing 
//                          Geophysical CFD software.
// ======================================================================================
// Version             :    0.1 
// Author              :    Xilin Xia (PhD candidate in Newcastle University)
// Create Time         :    2014/10/04
// Update Time         :    2012/10/29
// ======================================================================================
// Copyright @ Xilin Xia 2014 . All rights reserved.
// ======================================================================================

/*!
\file cuda_gauges_writer.h
\brief Header file for cuda simple field writer class

*/


#ifndef CUDA_GISASCII_WRITER_H
#define CUDA_GISASCII_WRITER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <cuda_runtime_api.h>
#include <cuda.h>
#include "Flag.h"
#include "Scalar.h"
#include "Vector.h"
#include "mesh_interface.h"
#include "mapped_field.h"
#include "cuda_mapped_field.h"
#include "cuda_kernel_launch_parameters.h"

namespace GC{

  class cuGisAsciiWriter{

  public:

    cuGisAsciiWriter(const char* filename);
    void write(cuFvMappedField<Scalar, on_cell>& phi, const char* filename, Scalar t, const char* directory = "output/");

  private:
    
    int n_rows;
    int n_cols;
    double x_ori;
    double y_ori;
    double cell_size;
    double nodata_value;
    std::vector< double > data;
    std::vector< int > indices;

  };

}

#endif
