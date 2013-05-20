
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_TEXT_01_2_A16_sa
.public _RES_TEXT_01_2_A16_SA;
.external __RES_TEXT_01_2_A16_ea;
.public _RES_TEXT_01_2_A16_EA;
.external __RES_NUM_1_A16_sa
.public _RES_NUM_1_A16_SA;
.external __RES_NUM_1_A16_ea;
.public _RES_NUM_1_A16_EA;
.external __RES_NUM_2_A16_sa
.public _RES_NUM_2_A16_SA;
.external __RES_NUM_2_A16_ea;
.public _RES_NUM_2_A16_EA;
.external __RES_NUM_3_A16_sa
.public _RES_NUM_3_A16_SA;
.external __RES_NUM_3_A16_ea;
.public _RES_NUM_3_A16_EA;
.external __RES_NUM_4_A16_sa
.public _RES_NUM_4_A16_SA;
.external __RES_NUM_4_A16_ea;
.public _RES_NUM_4_A16_EA;
.external __RES_NUM_5_A16_sa
.public _RES_NUM_5_A16_SA;
.external __RES_NUM_5_A16_ea;
.public _RES_NUM_5_A16_EA;
.external __RES_NUM_6_A16_sa
.public _RES_NUM_6_A16_SA;
.external __RES_NUM_6_A16_ea;
.public _RES_NUM_6_A16_EA;


_RES_Table:

_RES_TEXT_01_2_A16_SA:
	.DW offset __RES_TEXT_01_2_A16_sa,seg __RES_TEXT_01_2_A16_sa;
_RES_TEXT_01_2_A16_EA:
	.DW offset __RES_TEXT_01_2_A16_ea,seg __RES_TEXT_01_2_A16_ea;

_RES_NUM_1_A16_SA:
	.DW offset __RES_NUM_1_A16_sa,seg __RES_NUM_1_A16_sa;
_RES_NUM_1_A16_EA:
	.DW offset __RES_NUM_1_A16_ea,seg __RES_NUM_1_A16_ea;

_RES_NUM_2_A16_SA:
	.DW offset __RES_NUM_2_A16_sa,seg __RES_NUM_2_A16_sa;
_RES_NUM_2_A16_EA:
	.DW offset __RES_NUM_2_A16_ea,seg __RES_NUM_2_A16_ea;

_RES_NUM_3_A16_SA:
	.DW offset __RES_NUM_3_A16_sa,seg __RES_NUM_3_A16_sa;
_RES_NUM_3_A16_EA:
	.DW offset __RES_NUM_3_A16_ea,seg __RES_NUM_3_A16_ea;

_RES_NUM_4_A16_SA:
	.DW offset __RES_NUM_4_A16_sa,seg __RES_NUM_4_A16_sa;
_RES_NUM_4_A16_EA:
	.DW offset __RES_NUM_4_A16_ea,seg __RES_NUM_4_A16_ea;

_RES_NUM_5_A16_SA:
	.DW offset __RES_NUM_5_A16_sa,seg __RES_NUM_5_A16_sa;
_RES_NUM_5_A16_EA:
	.DW offset __RES_NUM_5_A16_ea,seg __RES_NUM_5_A16_ea;

_RES_NUM_6_A16_SA:
	.DW offset __RES_NUM_6_A16_sa,seg __RES_NUM_6_A16_sa;
_RES_NUM_6_A16_EA:
	.DW offset __RES_NUM_6_A16_ea,seg __RES_NUM_6_A16_ea;


// End Table
//------------------------------------------------
// SACM A1600 Speech Table
// -- User nees to add in the song/speech 
//    for playback based on the _RES_Table above.
//------------------------------------------------
.public T_SACM_A1600_SpeechTable;
T_SACM_A1600_SpeechTable:	
.dw _RES_TEXT_01_2_A16_SA
.dw _RES_NUM_1_A16_SA
.dw _RES_NUM_2_A16_SA
.dw _RES_NUM_3_A16_SA
.dw _RES_NUM_4_A16_SA
.dw _RES_NUM_5_A16_SA
.dw _RES_NUM_6_A16_SA
