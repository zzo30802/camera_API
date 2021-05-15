#ifndef _CAMERA_CREATOR_H_
#define _CAMERA_CREATOR_H_
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
  virtual bool OpenCameraID(const int &cam_index) const = 0;
  virtual bool StartStreaming(const int &cam_index) const = 0;
  virtual bool StopStreaming(const int &cam_index) const = 0;
  virtual void CloseCamera(const int &cam_index) = 0;
  virtual int GetAttribute(const int &cam_index, Cam::AttributeInt para) = 0;
  virtual double GetAttribute(const int &cam_index, Cam::AttributeDouble para) = 0;
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const = 0;
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const = 0;
  virtual cv::Mat GetFrame(const int &cam_index) = 0;
  virtual bool RestoreCameraSetting(const int &cam_index) const = 0;
  virtual bool ReadSetting(const int &cam_inde, const int &save_index) const = 0;
  virtual bool SaveSetting(const int &cam_index, const int &save_index) const = 0;
  virtual bool Trigger(const int &cam_index, Cam::TriggerMode mode) const = 0;
};

class CameraCreator : public CamInterface {
 public:
#ifdef _WIN32
  // common
  CAMS_API CameraCreator();
  CAMS_API ~CameraCreator();
  CAMS_API virtual std::vector<std::string> GetCameraVec();
  CAMS_API virtual bool OpenCameraID(const int &cam_index) const;
  CAMS_API virtual bool StartStreaming(const int &cam_index) const;
  CAMS_API virtual bool StopStreaming(const int &cam_index) const;
  CAMS_API virtual void CloseCamera(const int &cam_index);
  CAMS_API virtual int GetAttribute(const int &cam_index, Cam::AttributeInt para);
  CAMS_API virtual double GetAttribute(const int &cam_index, Cam::AttributeDouble para);
  CAMS_API virtual bool SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const;
  CAMS_API virtual bool SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const;
  CAMS_API virtual cv::Mat GetFrame(const int &cam_index);
  CAMS_API virtual bool RestoreCameraSetting(const int &cam_index) const;
  CAMS_API virtual bool ReadSetting(const int &cam_inde, const int &save_index) const;
  CAMS_API virtual bool SaveSetting(const int &cam_index, const int &save_index) const;
  CAMS_API virtual bool Trigger(const int &cam_index, Cam::TriggerMode mode) const;

  // others
  CAMS_API virtual std::vector<std::string> GetCameraList();
  CAMS_API virtual CameraBrand GetCameraBrand(const int &camIndex);
  CAMS_API virtual std::vector<std::string> GetAllCamList();
  CAMS_API virtual bool CreateCamInstanceByVector(std::vector<int> cam_index_vector) const;
  CAMS_API virtual int SetCamPtr(const int &cam_index);
  CAMS_API virtual void Release();
#else
  // common
  CameraCreator();
  ~CameraCreator();
  std::vector<std::string> GetCameraVec();
  virtual bool OpenCameraID(const int &cam_index) const;
  virtual bool StartStreaming(const int &cam_index) const;
  virtual bool StopStreaming(const int &cam_index) const;
  virtual void CloseCamera(const int &cam_index);
  virtual int GetAttribute(const int &cam_index, Cam::AttributeInt para);
  virtual double GetAttribute(const int &cam_index, Cam::AttributeDouble para);
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const;
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const;
  virtual cv::Mat GetFrame(const int &cam_index);
  virtual bool RestoreCameraSetting(const int &cam_index) const;
  virtual bool ReadSetting(const int &cam_inde, const int &save_index) const;
  virtual bool SaveSetting(const int &cam_index, const int &save_index) const;
  virtual bool Trigger(const int &cam_index, Cam::TriggerMode mode) const;

  // others
  virtual std::vector<std::string> GetAllCamList();
  virtual bool CreateCamInstanceByVector(std::vector<int> cam_index_vector_);
  virtual int SetCamPtr(int camIndex_);
  virtual void Release();
#endif
 private:
  // PIMPL
  class CameraCreatorPIMPL;
  std::auto_ptr<CameraCreatorPIMPL> p_camera_creator_pimpl;
};

#endif  // _CAMERA_CREATOR_H_