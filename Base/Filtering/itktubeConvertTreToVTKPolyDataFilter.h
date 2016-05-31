/*=========================================================================

   Library:   TubeTK

   Copyright 2010 Kitware Inc. 28 Corporate Drive,
   Clifton Park, NY, 12065, USA.

   All rights reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

=========================================================================*/

#ifndef __itktubeConvertTreToVTKPolyDataFilter_h
#define __itktubeConvertTreToVTKPolyDataFilter_h

#include "itkGroupSpatialObject.h"
#include "itkImage.h"
#include "itktubeSpatialObjectToSpatialObjectFilter.h"
#include "itkVesselTubeSpatialObject.h"
#include "itkVesselTubeSpatialObjectPoint.h"
namespace itk
{
namespace tube
{

/** \class CropTubesFilter
 * \brief Crop tubes spatial object based on a volume map or a bounding box.
 *
 */
template< unsigned int VDimension >
class ConvertTreToVTKPolyDataFilter
  : public SpatialObjectToSpatialObjectFilter<
    GroupSpatialObject< VDimension >, GroupSpatialObject< VDimension > >
{
public:
  /** Standard class typedefs. */
  typedef GroupSpatialObject< VDimension >          TubeGroupType;

  typedef ConvertTreToVTKPolyDataFilter              Self;
  typedef SpatialObjectToSpatialObjectFilter< TubeGroupType, TubeGroupType >
                                                     Superclass;
  typedef SmartPointer< Self >                       Pointer;
  typedef SmartPointer< const Self >                 ConstPointer;
  typedef VesselTubeSpatialObject< VDimension >      TubeType;
  typedef VesselTubeSpatialObjectPoint< VDimension > TubePointType;

  typedef double                                     PixelType;
  typedef itk::Image< PixelType, VDimension >        ImageType;
  typedef itk::Vector< PixelType, VDimension >       VectorType;
  typedef itk::Point< double, VDimension >           PointType;

  /** Run-time type information (and related methods).   */
  itkTypeMacro( ConvertTreToVTKPolyDataFilter,
                SpatialObjectToSpatialObjectFilter );

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Set/Get mask image */
  itkSetObjectMacro( InputImage, ImageType );
  itkGetObjectMacro( InputImage, ImageType );

protected:
  ConvertTreToVTKPolyDataFilter( void );
  virtual ~ConvertTreToVTKPolyDataFilter( void );

  virtual void GenerateData( void );

  void PrintSelf( std::ostream & os, Indent indent ) const;

private:
  // purposely not implemented
  ConvertTreToVTKPolyDataFilter( const Self & );
  // purposely not implemented
  void operator=( const Self & );

  typename ImageType::Pointer m_InputImage;

}; // End class ConvertTreToVTKPolyDataFilter

} // End namespace tube
} // End namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itktubeConvertTreToVTKPolyDataFilter.hxx"
#endif

#endif // End !defined(__itktubeConvertTreToVTKPolyDataFilter_h)
