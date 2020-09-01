/******************************************************************
** 文件名: maxsublen.cpp
** 创建人: BanMing 
** 日  期: 8/2020, 10:33:34 AM
** 描  述:  最大子序

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*************************************************************/
#include<iostream>
#include<vector>
using namespace std;
int GetSubLen(vector<int> nums){
 

  if (nums.size()<1)
  {
      return 0;
  }
   int maxSum=nums[0]>0?nums[0]:maxSum;
   if (nums.size()==1)
  {
      return maxSum;
  }
   for (size_t i = 1; i < nums.size(); i++)
   {
       maxSum+=nums[i]>0?nums[i]:0;
   }
   
    return maxSum;
}                 
