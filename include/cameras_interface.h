#ifndef _CAMERAS_INTERFACE_H
#define _CAMERAS_INTERFACE_H
#include <map>
#include <memory>
#include <vector>

#include "attribute.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

/**
 * 定義各種camera的基本功能
 **/

// 如果再project添加CAMERAS_EXPORTS關鍵字，那CAMS_API就表示替代__declspec(dllexport)
// 用於dll的匯出
// https://docs.microsoft.com/zh-tw/cpp/build/importing-into-an-application-using-declspec-dllimport?view=msvc-160
#ifndef CAMERAS_EXPORTS
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

class CameraCreator : public CamInterface {
 public:
#ifdef _WIN32
  CAMS_API std::vector<std::string> GetCameraVec();
  CAMS_API int OpenCameraID(const int &cam_index);
  CAMS_API int StartStreaming(const int &cam_index);
  CAMS_API int StopStreaming(const int &cam_index);
  CAMS_API void CloseCamera(const int &cam_index);
  CAMS_API int GetAttribute(const int &cam_index, Cam::AttributeInt para);
  CAMS_API double GetAttribute(const int &cam_index, Cam::AttributeDouble para);
  CAMS_API int SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value);
  CAMS_API int SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value);
  CAMS_API cv::Mat GetFrame(const int &cam_index);
  CAMS_API bool RestoreCameraSetting(const int &cam_index);
  CAMS_API bool ReadSetting(const int &cam_inde, const int &save_index);
  CAMS_API bool SaveSetting(const int &cam_index, const int &save_index);
  CAMS_API bool Trigger(const int &cam_index, Cam::TriggerMode mode);
#else
  std::vector<std::string> GetCameraVec();
  int OpenCameraID(const int &cam_index);
  int StartStreaming(const int &cam_index);
  int StopStreaming(const int &cam_index);
  void CloseCamera(const int &cam_index);
  int GetAttribute(const int &cam_index, Cam::AttributeInt para);
  double GetAttribute(const int &cam_index, Cam::AttributeDouble para);
  int SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value);
  int SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value);
  cv::Mat GetFrame(const int &cam_index);
  bool RestoreCameraSetting(const int &cam_index);
  bool ReadSetting(const int &cam_inde, const int &save_index);
  bool SaveSetting(const int &cam_index, const int &save_index);
  bool Trigger(const int &cam_index, Cam::TriggerMode mode);
#endif
 private:
  // PIMPL
  class CameraCreatorPIMPL;
  std::auto_ptr<CameraCreatorPIMPL> p_CameraCreatorPIMPL;
};

#endif  // _CAMERAS_INTERFACE_H