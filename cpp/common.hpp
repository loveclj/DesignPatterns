//
// Created by lizhifeng on 10/13/16.
//

#ifndef PATTERN_DESIGN_COMMON_HPP
#define PATTERN_DESIGN_COMMON_HPP

#define SAFE_DELETE_PTR(PTR) \
     if(PTR != NULL){\
         delete PTR;\
         PTR = NULL;\
     }

#define SAFE_DELETE_ARRAY(ARRAY)\
     if(ARRAY != NULL){\
      delete [] ARRAY;\
      ARRAY = NULL;\
      }




#endif //PATTERN_DESIGN_COMMON_HPP
