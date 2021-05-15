#include "ids/ids_impl.h"
Ids::Ids() : p_ids_pimpl(new IdsPIMPL) {}
Ids::~Ids() {}

// PIMPL : via private class pointer to hide implementation
std::vector<std::string> Ids::GetCameraVec() {
  return p_ids_pimpl->GetCameraVec();
}
bool Ids::OpenCameraID(const int &cam_index) const {
  return p_ids_pimpl->OpenCameraID(cam_index);
}
bool Ids::StartStreaming(const int &cam_index) const {
  return p_ids_pimpl->StartStreaming(cam_index);
}
bool Ids::StopStreaming(const int &cam_index) const {
  return p_ids_pimpl->StopStreaming(cam_index);
}
void Ids::CloseCamera(const int &cam_index) {
  return p_ids_pimpl->CloseCamera(cam_index);
}
int Ids::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  return p_ids_pimpl->GetAttribute(cam_index, para);
}
double Ids::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  return p_ids_pimpl->GetAttribute(cam_index, para);
}
bool Ids::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const {
  return p_ids_pimpl->SetAttribute(cam_index, para, value);
}
bool Ids::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const {
  return p_ids_pimpl->SetAttribute(cam_index, para, value);
}
cv::Mat Ids::GetFrame(const int &cam_index) {
  return p_ids_pimpl->GetFrame(cam_index);
}
bool Ids::RestoreCameraSetting(const int &cam_index) const {
  return p_ids_pimpl->RestoreCameraSetting(cam_index);
}
bool Ids::ReadSetting(const int &cam_index, const int &save_index) const {
  return p_ids_pimpl->ReadSetting(cam_index, save_index);
}
bool Ids::SaveSetting(const int &cam_index, const int &save_index) const {
  return p_ids_pimpl->SaveSetting(cam_index, save_index);
}
bool Ids::Trigger(const int &cam_index, Cam::TriggerMode mode) const {
  return p_ids_pimpl->Trigger(cam_index, mode);
}

// implement others function
