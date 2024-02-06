/**
  * @file        __fix_index_xxx.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Fix matrix row index and column index in some functions
  * @attention
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|06-MAY-2022|modify exception
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Matrix
  * @{
  */

size_t __fix_index_row(size_t i) {
  return --i;
}

size_t __fix_index_column(size_t j) {
  return --j;
}

/**
  * @}
  */