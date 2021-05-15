#ifndef _FLIR_IMPL_H_
#define _FLIR_IMPL_H_
#include <condition_variable>
#include <mutex>

#include "MultiThreadSafe.h"
#include "Spinnaker.h"
#include "flir/flir.h"
using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;

/**
 * implement all function to operate flir camera
**/
class Flir::FlirPIMPL {
 public:
  FlirPIMPL();
  ~FlirPIMPL();
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
  // SystemPtr -> CameraList -> CameraPtr
  CameraPtr *pCamList;  // pointer to camera
  SystemPtr system;     // flir camera system object (singleton)
  CameraList camList;
  InterfaceList interfaceList;
  /* flag to check the camrea status*/
  std::vector<bool> m_beginAcquisition;
  // about trigger mode
  std::vector<bool> m_trigger_continuous;
  std::vector<bool> m_trigger_hardware_HI_LO;
  std::vector<bool> m_trigger_hardware_LO_HI;
  std::vector<bool> m_trigger_software;
  // about thread
  std::vector<bool> m_start_thread_continuous;
  std::vector<bool> m_stop_thread;
  std::vector<bool> m_is_closecamera;
  // multi-queue thread-safe to store image frame
  Concurrency::ThreadSafe<cv::Mat> thread_safe;
  /**
   * ...
   * Others virables & functions
   * ...
  **/
};
#endif  // _FLIR_IMPL_H_