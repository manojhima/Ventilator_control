#include "gtest/gtest.h"
#include "../../../inc/DATABASE/DB_Compute.h"

TEST(DB_ComputeWrite, test1){
	e_DB_COMPUTE Id = BLOWER_COMMAND_U16; 
	UWORD16 value = 6;
	UWORD16 v1 = 6;
	ASSERT_EQ(v1,DB_ComputeWrite(Id,value));
}
