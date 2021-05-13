#ifndef _CAMERA_CREATOR_H_
#define _CAMERA_CREATOR_H_

#include "cameras_interface.h"

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

class CameraCreator::CameraCreatorPIMPL : public CamInterface {
 public:
  CameraCreatorPIMPL();
  ~CameraCreatorPIMPL();
  // implement all pure virtual function
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

  // multiple cameras connection
  std::vector<std::string> GetAllCamList();
  bool CreateCamInstanceByVector(std::vector<int> cam_index_vector_);
  int SetCamPtr(int camIndex_);

 private:
  // make_unique
  template <typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args &&...args);
  // all brand of camera vector
  std::vector<std::string> camera_A_vec;
  std::vector<std::string> camera_B_vec;
  // total camera vector
  std::vector<std::string> all_cameras_vec;
  std::shared_ptr<CamInterface> camPtr;
  // mapping camera order
  std::map<int, CamMap> normal_map;
  std::map<int, CamMap> order_map;
  //
  std::shared_ptr<Flir> camera_A_ptr;
  std::shared_ptr<Ids> camera_B_ptr;
};

#endif  // _CAMERA_CREATOR_H_