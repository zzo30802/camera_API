#ifndef _CAMERAS_INTERFACE_H
#define _CAMERAS_INTERFACE_H

#include <vector>

#include "cameras_creator.h"
#include "flir/flir.h"
#include "ids/ids.h"
#ifndef CAMERAS_EXPORTS
#define CAMS_API __declspec(dllexport)
#else
#define CAMS_API __declspec(dllimport)
#endif

struct CamMap {
  int inside_index;
  int outside_index;
  std::string camera_type;
};

/**
 * For example:
 * input camera brand     : flir   ids
 * input number of camera : 1,2,3  4,5
 * if we select 1,3,5 index of camera list to open, and then we will map it to 0,1,2
 * so if you want to operate the flir camera and its index is "3", you have to give the index "1"
 * to the following function (cam_index)
 * 
 * 1,3,5 -> 0,1,2
**/

class CameraCreator::CameraCreatorPIMPL : public CameraCreator {
 public:
  CameraCreatorPIMPL();
  ~CameraCreatorPIMPL();
  // implement all pure virtual function
  virtual std::vector<std::string> GetCameraVec() override;
  virtual bool OpenCameraID(const int &cam_index) const override;
  virtual bool StartStreaming(const int &cam_index) const override;
  virtual bool StopStreaming(const int &cam_index) const override;
  virtual void CloseCamera(const int &cam_index) override;
  virtual int GetAttribute(const int &cam_index, Cam::AttributeInt para) override;
  virtual double GetAttribute(const int &cam_index, Cam::AttributeDouble para) override;
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const override;
  virtual bool SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const override;
  virtual cv::Mat GetFrame(const int &cam_index) override;
  virtual bool RestoreCameraSetting(const int &cam_index) const override;
  virtual bool ReadSetting(const int &cam_inde, const int &save_index) const override;
  virtual bool SaveSetting(const int &cam_index, const int &save_index) const override;
  virtual bool Trigger(const int &cam_index, Cam::TriggerMode mode) const override;

  // multiple cameras connection
  virtual std::vector<std::string> GetCameraList() override;
  virtual CameraBrand GetCameraBrand(const int &camIndex) override;
  virtual std::vector<std::string> GetAllCamList() override;
  virtual bool CreateCamInstanceByVector(std::vector<int> cam_index_vector) const override;
  virtual int SetCamPtr(const int &cam_index) override;
  virtual void Release() override;

 private:
  // make_unique
  template <typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args &&...args);
  // all brand of camera vector
  std::vector<std::string> flir_cam_vec;
  std::vector<std::string> ids_cam_vec;
  // total camera vector
  std::vector<std::string> all_cameras_vec;
  std::shared_ptr<CamInterface> camPtr;
  // mapping camera order
  std::map<int, CamMap> normal_map;
  std::map<int, CamMap> order_map;
  //
  std::shared_ptr<Flir> flir_ptr;
  std::shared_ptr<Ids> ids_ptr;
};

#endif  // _CAMERAS_INTERFACE_H