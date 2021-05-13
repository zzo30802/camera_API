#ifndef _FLIR_H_
#define _FLIR_H_
#include "attribute.h"
#include "cameras_interface.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Flir : public CamInterface {
 public:
  Flir();
  ~Flir();

 private:
};

#endif  // _FLIR_H_