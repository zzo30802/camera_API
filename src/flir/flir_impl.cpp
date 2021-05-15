#include "flir/flir_impl.h"
Flir::Flir() : p_flir_pimpl(new FlirPIMPL) {}
Flir::~Flir() {}
// PIMPL : via private class pointer to hide implementation
std::vector<std::string> Flir::GetCameraVec() {
  return p_flir_pimpl->GetCameraVec();
}
bool Flir::OpenCameraID(const int &cam_index) const {
  return p_flir_pimpl->OpenCameraID(cam_index);
}
bool Flir::StartStreaming(const int &cam_index) const {
  return p_flir_pimpl->StartStreaming(cam_index);
}
bool Flir::StopStreaming(const int &cam_index) const {
  return p_flir_pimpl->StopStreaming(cam_index);
}
void Flir::CloseCamera(const int &cam_index) {
  return p_flir_pimpl->CloseCamera(cam_index);
}
int Flir::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  return p_flir_pimpl->GetAttribute(cam_index, para);
}
double Flir::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  return p_flir_pimpl->GetAttribute(cam_index, para);
}
bool Flir::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const {
  return p_flir_pimpl->SetAttribute(cam_index, para, value);
}
bool Flir::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const {
  return p_flir_pimpl->SetAttribute(cam_index, para, value);
}
cv::Mat Flir::GetFrame(const int &cam_index) {
  return p_flir_pimpl->GetFrame(cam_index);
}
bool Flir::RestoreCameraSetting(const int &cam_index) const {
  return p_flir_pimpl->RestoreCameraSetting(cam_index);
}
bool Flir::ReadSetting(const int &cam_index, const int &save_index) const {
  return p_flir_pimpl->ReadSetting(cam_index, save_index);
}
bool Flir::SaveSetting(const int &cam_index, const int &save_index) const {
  return p_flir_pimpl->SaveSetting(cam_index, save_index);
}
bool Flir::Trigger(const int &cam_index, Cam::TriggerMode mode) const {
  return p_flir_pimpl->Trigger(cam_index, mode);
}

// *****implement others function*****

// constructor to get the camera system instance
Flir::FlirPIMPL::FlirPIMPL() {
  this->system = System::GetInstance();
}

Flir::FlirPIMPL::~FlirPIMPL() {
  try {
    /*
    1. all cameraPtr point to nullptr
    2. delete cameraPtrList
    */
  } catch (Spinnaker::Exception &e) {
    std::cout << "Flir::~FlirClass() : " << e.what() << std::endl;
  } catch (...) {
    std::cout << "Flir::~FlirClass() : program interrupted" << std::endl;
  }
}

std::vector<std::string> Flir::FlirPIMPL::GetCameraVec() {
  // 1. intialize all trigger flag
  /**
   * ...code... 
  **/
  // 2. Check all camera devices that the PC is connected to.
  /**
   * ...code... 
  **/
  // 3. Auto Focus all cameras IP, and get the number of connected cameras.
  camera_total_num = camList.GetSize();
  // 4. According to the number of connected cameras, create the same number of thread-safe.
  thread_safe.CreateMultiQueueVec(camera_total_num);
  // 5. Create all camera context && information.
}
bool Flir::FlirPIMPL::OpenCameraID(const int &cam_index) const {
  // code
}
bool Flir::FlirPIMPL::StartStreaming(const int &cam_index) const {
  // code
}
bool Flir::FlirPIMPL::StopStreaming(const int &cam_index) const {
  // code
}
void Flir::FlirPIMPL::CloseCamera(const int &cam_index) {
  // code
}
int Flir::FlirPIMPL::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  // code
}
double Flir::FlirPIMPL::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  // code
}
bool Flir::FlirPIMPL::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const {
  // code
}
bool Flir::FlirPIMPL::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const {
  // code
}
cv::Mat Flir::FlirPIMPL::GetFrame(const int &cam_index) {
  cv::Mat img;
  if (!this->thread_safe.IsEmpty(cam_index) && !is_stop_thread[cam_index]) {
    std::shared_ptr<cv::Mat> p_img = this->thread_safe.TryPop(cam_index);
    if (!p_img) {
      std::cout << "Flir::GetFrame() : get p_img from thread_safe is empty." << std::endl;
      return img;
    }
    return *(p_img.get());
  } else {
    return img;
  }
}
bool Flir::FlirPIMPL::RestoreCameraSetting(const int &cam_index) const {
  // code
}
bool Flir::FlirPIMPL::ReadSetting(const int &cam_inde, const int &save_index) const {
  // code
}
bool Flir::FlirPIMPL::SaveSetting(const int &cam_index, const int &save_index) const {
  // code
}
bool Flir::FlirPIMPL::Trigger(const int &cam_index, Cam::TriggerMode mode) const {
  // code
}