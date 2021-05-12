#ifndef _CAMERAS_INTERFACE_H
#define _CAMERAS_INTERFACE_H
#include "attribute.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#ifndef camsmodule_EXPORTS
#define CAMS_API __declspec(dllexport)
#else
#define CAMS_API __declspec(dllimport)
#endif

/**
 * Define functions to operate the camera.
 * According to cam_index to select which camera you want to operate. 
 **/
class CamInterface {
 public:
  virtual std::vector<std::string> GetCameraVec() = 0;
  virtual int OpenCameraID(const int &cam_index) = 0;
  virtual int StartStreaming(const int &cam_index) = 0;
  virtual int StopStreaming(const int &cam_index) = 0;
  virtual void CloseCamera(const int &cam_index) = 0;
  virtual int GetAttribute(const int &cam_index, Cam::AttributeInt para) = 0;
  virtual double GetAttribute(const int &cam_index, Cam::AttributeDouble para) = 0;
  virtual int SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) = 0;
  virtual int SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) = 0;
  virtual cv::Mat GetFrame(const int &cam_index) = 0;
  virtual bool RestoreCameraSetting(const int &cam_index) = 0;
  virtual bool ReadSetting(const int &cam_inde, const int &save_index) = 0;
  virtual bool SaveSetting(const int &cam_index, const int &save_index) = 0;
  virtual bool Trigger(const int &cam_index, Cam::TriggerMode mode) = 0;
};
#endif  // _CAMERAS_INTERFACE_H