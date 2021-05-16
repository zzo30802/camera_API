#include <chrono>
#include <iostream>
#include <iterator>

#include "cameras_impl.h"
//-----------------------------------
// PIMPL
CameraCreator::CameraCreator() : p_camera_creator_pimpl(new CameraCreatorPIMPL) {}
CameraCreator::~CameraCreator() {}
std::vector<std::string> CameraCreator::GetCameraVec() {
  return p_camera_creator_pimpl->GetCameraVec();
}
bool CameraCreator::OpenCameraID(const int &cam_index) {
  return p_camera_creator_pimpl->OpenCameraID(cam_index);
}
bool CameraCreator::StartStreaming(const int &cam_index) {
  return p_camera_creator_pimpl->StartStreaming(cam_index);
}
bool CameraCreator::StopStreaming(const int &cam_index) {
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
bool CameraCreator::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) {
  return p_camera_creator_pimpl->SetAttribute(cam_index, para, value);
}
bool CameraCreator::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) {
  return p_camera_creator_pimpl->SetAttribute(cam_index, para, value);
}
cv::Mat CameraCreator::GetFrame(const int &cam_index) {
  return p_camera_creator_pimpl->GetFrame(cam_index);
}
bool CameraCreator::RestoreCameraSetting(const int &cam_index) {
  return p_camera_creator_pimpl->RestoreCameraSetting(cam_index);
}
bool CameraCreator::ReadSetting(const int &cam_inde, const int &save_index) {
  return p_camera_creator_pimpl->ReadSetting(cam_inde, save_index);
}
bool CameraCreator::SaveSetting(const int &cam_index, const int &save_index) {
  return p_camera_creator_pimpl->SaveSetting(cam_index, save_index);
}
bool CameraCreator::Trigger(const int &cam_index, Cam::TriggerMode mode) {
  return p_camera_creator_pimpl->Trigger(cam_index, mode);
}
std::vector<std::string> CameraCreator::GetAllCamList() {
  return p_camera_creator_pimpl->GetAllCamList();
}
bool CameraCreator::CreateCamInstanceByVector(std::vector<int> &cam_index_vector) {
  return p_camera_creator_pimpl->CreateCamInstanceByVector(cam_index_vector);
}
int CameraCreator::SetCamPtr(const int &cam_index) {
  return p_camera_creator_pimpl->SetCamPtr(cam_index);
}
void CameraCreator::Release() {
  p_camera_creator_pimpl->Release();
}
//-----------------------------------
// consturctor to get all shared_ptr instances
CameraCreator::CameraCreatorPIMPL::CameraCreatorPIMPL() : flir_ptr(std::make_shared<Flir>()),
                                                          ids_ptr(std::make_shared<Ids>()) {
  this->curr_camera_status = "default";
}
CameraCreator::CameraCreatorPIMPL::~CameraCreatorPIMPL() {}
bool CameraCreator::CameraCreatorPIMPL::OpenCameraID(const int &cam_index) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->OpenCameraID(mapping_cam_index);
}

bool CameraCreator::CameraCreatorPIMPL::StartStreaming(const int &cam_index) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->StartStreaming(cam_index);
}
bool CameraCreator::CameraCreatorPIMPL::StopStreaming(const int &cam_index) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->StopStreaming(mapping_cam_index);
}
void CameraCreator::CameraCreatorPIMPL::CloseCamera(const int &cam_index) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->CloseCamera(cam_index);
}
int CameraCreator::CameraCreatorPIMPL::GetAttribute(const int &cam_index, Cam::AttributeInt para) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->GetAttribute(mapping_cam_index, para);
}
double CameraCreator::CameraCreatorPIMPL::GetAttribute(const int &cam_index, Cam::AttributeDouble para) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->GetAttribute(mapping_cam_index, para);
}
bool CameraCreator::CameraCreatorPIMPL::SetAttribute(const int &cam_index, Cam::AttributeInt para, const int &value) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->SetAttribute(mapping_cam_index, para, value);
}
bool CameraCreator::CameraCreatorPIMPL::SetAttribute(const int &cam_index, Cam::AttributeDouble para, const double &value) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->SetAttribute(mapping_cam_index, para, value);
}
cv::Mat CameraCreator::CameraCreatorPIMPL::GetFrame(const int &cam_index) {
  const int &&mapping_cam_index = SetCamPtr(cam_index);
  return this->camPtr->GetFrame(mapping_cam_index);
}
bool CameraCreator::CameraCreatorPIMPL::RestoreCameraSetting(const int &cam_index) {
  // code
}
bool CameraCreator::CameraCreatorPIMPL::ReadSetting(const int &cam_inde, const int &save_index) {
  // code
}
bool CameraCreator::CameraCreatorPIMPL::SaveSetting(const int &cam_index, const int &save_index) {
  // code
}
bool CameraCreator::CameraCreatorPIMPL::Trigger(const int &cam_index, Cam::TriggerMode mode) {
  // code
}
//-----------------------------------
std::vector<std::string> CameraCreator::CameraCreatorPIMPL::GetAllCamList() {
  //-----reset all camera vector-----
  // flir
  this->flir_cam_vec.clear();
  this->flir_cam_vec.shrink_to_fit();
  // ids
  this->ids_cam_vec.clear();
  this->ids_cam_vec.shrink_to_fit();
  // all
  this->all_cameras_vec.clear();
  this->all_cameras_vec.shrink_to_fit();
  //-----Get all camera model vector-----
  this->flir_cam_vec = this->flir_ptr->GetCameraVec();
  this->ids_cam_vec = this->ids_ptr->GetCameraVec();
  //-----combine all camera model vectors into one vector-----
  const int &&number_of_cameras = this->flir_cam_vec.size() + this->ids_cam_vec.size();
  this->all_cameras_vec.reserve(number_of_cameras);
  this->all_cameras_vec.insert(this->all_cameras_vec.end(), this->flir_cam_vec.begin(), this->flir_cam_vec.end());
  this->all_cameras_vec.insert(this->all_cameras_vec.end(), this->ids_cam_vec.begin(), this->ids_cam_vec.end());
  //-----The camera index is arranged according to the camera brand-----
  // mapping camera index
  const int &number_of_flir_cams = this->flir_cam_vec.size();
  const int &number_of_ids_cams = this->ids_cam_vec.size();
  int external_index = 0;
  for (int i = 0; i < this->all_cameras_vec.size(); i++) {
    //flir
    if (i < number_of_flir_cams) {
      CamMap mapping_table;
      mapping_table.internal_index = i;
      mapping_table.external_index = external_index;
      mapping_table.camera_brand = "flir";
      this->normal_map[external_index++] = mapping_table;
    }
    //ids
    else if (number_of_flir_cams <= i && i < (number_of_flir_cams + number_of_ids_cams)) {
      const int &&index_ = i - number_of_flir_cams;
      CamMap mapping_table;
      mapping_table.internal_index = index_;
      mapping_table.external_index = external_index;
      mapping_table.camera_brand = "ids";
      this->normal_map[external_index++] = mapping_table;
    }
  }
  return this->all_cameras_vec;
}
bool CameraCreator::CameraCreatorPIMPL::CreateCamInstanceByVector(std::vector<int> &cam_index_vector) {
  this->order_map.clear();
  bool is_done_flir{false}, is_done_ids{false};
  // check input vector
  if (cam_index_vector.empty()) {
    std::cout << "\tError: CameraCreator::CameraCreatorPIMPL::CreateCamInstanceByVector" << std::endl;
    std::cout << "\tcam_index_vector is empty." << std::endl;
    return false;
  }
  // check if any camera is conntected.
  if (this->all_cameras_vec.empty()) {
    return false;
  }
  // start mapping camera index
  for (int i = 0; i < cam_index_vector.size(); i++) {
    std::map<int, CamMap>::const_iterator &&iter = this->normal_map.find(cam_index_vector[i]);
    if (iter == this->normal_map.end()) {  // if not found the index in the map table
      return false;
    }
    this->order_map[i] = iter->second;
  }
  return true;
}
int CameraCreator::CameraCreatorPIMPL::SetCamPtr(const int &cam_index) {
  if (this->order_map.empty()) {
    std::cout << "Error: CameraCreator::CameraCreatorPIMPL::SetCamPtr()" << std::endl;
    std::cout << "\torder_map ise empty." << std::endl;
    return -1;  // fail
  }
  std::map<int, CamMap>::const_iterator &&iter = this->order_map.find(cam_index);
  if (iter == this->order_map.end()) {
    std::cout << "Error: CameraCreator::CameraCreatorPIMPL::SetCamPtr()" << std::endl;
    std::cout << "\tNot found the cam_index in the order_map." << std::endl;
    return -1;
  }
  // flir
  if (iter->second.camera_brand == "flir") {
    // check the current camPtr is the same as the target or not
    if (this->curr_camera_status != "flir") {
      this->camPtr = this->flir_ptr;
      this->curr_camera_status = "flir";
    }
  }
  // ids
  else if (iter->second.camera_brand == "ids") {
    if (this->curr_camera_status != "ids") {
      this->camPtr = this->ids_ptr;
      this->curr_camera_status = "ids";
    }
  }
  return iter->second.internal_index;
}
void CameraCreator::CameraCreatorPIMPL::Release() {
  this->camPtr = nullptr;
  this->flir_ptr = nullptr;
  this->ids_ptr = nullptr;
}