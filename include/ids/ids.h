#ifndef _IDS_H_
#define _IDS_H_
#include "attribute.h"
#include "cameras_creator.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Ids : public CamInterface {
 public:
  Ids();
  ~Ids();
  std::vector<std::string> GetCameraVec();
  bool OpenCameraID(const int &cam_index) const;
  bool StartStreaming(const int &cam_index) const;
  bool StopStreaming(const int &cam_index) const;
  void CloseCamera(const int &cam_index);
  int GetAttribute(const int &cam_index, Cam::AttributeInt para);
  double GetAttribute(const int &cam_index, Cam::AttributeDouble para);
  bool SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const;
  bool SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const;
  cv::Mat GetFrame(const int &cam_index);
  bool RestoreCameraSetting(const int &cam_index) const;
  bool ReadSetting(const int &cam_inde, const int &save_index) const;
  bool SaveSetting(const int &cam_index, const int &save_index) const;
  bool Trigger(const int &cam_index, Cam::TriggerMode mode) const;

 private:
  class IdsPIMPL;
  std::auto_ptr<IdsPIMPL> p_ids_pimpl;
};

#endif  // _IDS_H_