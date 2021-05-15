#include <chrono>
#include <iostream>

#include "cameras_impl.h"
// PIMPL
CameraCreator::CameraCreator() : p_camera_creator_pimpl(new CameraCreatorPIMPL) {}
CameraCreator::~CameraCreator() {}
std::vector<std::string> CameraCreator::GetCameraVec() {
  return p_camera_creator_pimpl->GetCameraVec();
}
bool CameraCreator::OpenCameraID(const int &cam_index) const {
  return p_camera_creator_pimpl->OpenCameraID(cam_index);
}
bool CameraCreator::StartStreaming(const int &cam_index) const {
  return p_camera_creator_pimpl->StartStreaming(cam_index);
}
bool CameraCreator::StopStreaming(const int &cam_index) const {
  return p_camera_creator_pimpl->StopStreaming(cam_index);
}
void CameraCreator::CloseCamera(const int &cam_index) {
  return p_camera_creator_pimpl->CloseCamera(cam_index);
}
int CameraCreator::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  return p_camera_creator_pimpl->GetAttribute(cam_index, para);
}
double CameraCreator::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  return p_camera_creator_pimpl->GetAttribute(cam_index, para);
}
bool CameraCreator::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const {
  return p_camera_creator_pimpl->SetAttribute(cam_index, para, value);
}
bool CameraCreator::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const {
  return p_camera_creator_pimpl->SetAttribute(cam_index, para, value);
}
cv::Mat CameraCreator::GetFrame(const int &cam_index) {
  return p_camera_creator_pimpl->GetFrame(cam_index);
}
bool CameraCreator::RestoreCameraSetting(const int &cam_index) const {
  return p_camera_creator_pimpl->RestoreCameraSetting(cam_index);
}
bool CameraCreator::ReadSetting(const int &cam_inde, const int &save_index) const {
  return p_camera_creator_pimpl->ReadSetting(cam_inde, save_index);
}
bool CameraCreator::SaveSetting(const int &cam_index, const int &save_index) const {
  return p_camera_creator_pimpl->SaveSetting(cam_index, save_index);
}
bool CameraCreator::Trigger(const int &cam_index, Cam::TriggerMode mode) const {
  return p_camera_creator_pimpl->Trigger(cam_index, mode);
}
std::vector<std::string> CameraCreator::GetAllCamList() {
  return p_camera_creator_pimpl->GetAllCamList();
}
bool CameraCreator::CreateCamInstanceByVector(std::vector<int> cam_index_vector) const {
  return p_camera_creator_pimpl->CreateCamInstanceByVector(cam_index_vector);
}
int CameraCreator::SetCamPtr(const int &cam_index) {
  return p_camera_creator_pimpl->SetCamPtr(cam_index);
}
void CameraCreator::Release() {
  p_camera_creator_pimpl->Release();
}

CameraCreator::CameraCreatorPIMPL::CameraCreatorPIMPL() : flir_ptr(std::make_shared<Flir>()),
                                                          ids_ptr(std::make_shared<Ids>());
CameraCreator::CameraCreatorPIMPL::~CameraCreatorPIMPL() {}
std::vector<std::string> CameraCreator::CameraCreatorPIMPL::GetAllCamList() {
  // code
}
bool CameraCreator::CameraCreatorPIMPL::OpenCameraID(const int &cam_index) const {
}

bool CameraCreator::CameraCreatorPIMPL::StartStreaming(const int &cam_index) const {
}
bool CameraCreator::CameraCreatorPIMPL::StopStreaming(const int &cam_index) const {
}
void CloseCamera(const int &cam_index) {
}
int CameraCreator::CameraCreatorPIMPL::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->GetAttribute(mapping_cam_index, para);
}
double CameraCreator::CameraCreatorPIMPL::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->GetAttribute(mapping_cam_index, para);
}
bool CameraCreator::CameraCreatorPIMPL::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) const {
}
bool CameraCreator::CameraCreatorPIMPL::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) const {
}
cv::Mat CameraCreator::CameraCreatorPIMPL::GetFrame(const int &cam_index) {
}
bool CameraCreator::CameraCreatorPIMPL::RestoreCameraSetting(const int &cam_index) const {
}
bool CameraCreator::CameraCreatorPIMPL::ReadSetting(const int &cam_inde, const int &save_index) const {
}
bool CameraCreator::CameraCreatorPIMPL::SaveSetting(const int &cam_index, const int &save_index) const {
}
bool CameraCreator::CameraCreatorPIMPL::Trigger(const int &cam_index, Cam::TriggerMode mode) const {
}
std::vector<std::string> CameraCreator::CameraCreatorPIMPL::GetCameraList() {
}
CameraBrand CameraCreator::CameraCreatorPIMPL::GetCameraBrand(const int &camIndex) {
}
std::vector<std::string> CameraCreator::CameraCreatorPIMPL::GetAllCamList() {
}
bool CameraCreator::CameraCreatorPIMPL::CreateCamInstanceByVector(std::vector<int> cam_index_vector) const {
}
int CameraCreator::CameraCreatorPIMPL::SetCamPtr(const int &cam_index) {
}
void CameraCreator::CameraCreatorPIMPL::Release() {
}