
/* #line 1 "./ragel/tmedia_imageattr.rl" */
/*
* Copyright (C) 2012-2015 Doubango Telecom <http://www.doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tmedia_imageattr.c
 * @brief 'image-attr' parser as per RFC 6236
 */
#include "tinymedia/tmedia_imageattr.h"

#include "tsk_ragel_state.h"
#include "tsk_debug.h"

#include <stdlib.h>

/***********************************
*	Ragel state machine.
*/

/* #line 135 "./ragel/tmedia_imageattr.rl" */


static int tmedia_imageattr_reset(tmedia_imageattr_xt* self)
{
	if(self){
		tsk_size_t i;
		memset(self, 0, sizeof(*self));
		for(i = 0; i < TMEDIA_imageattr_ARRAY_MAX_SIZE; ++i){
			self->send.sets[i].qvalue = 0.5;
			self->recv.sets[i].qvalue = 0.5;
		}
		return 0;
	}
	TSK_DEBUG_ERROR("Invalid parameter");
	return -1;
}

int tmedia_imageattr_parse(tmedia_imageattr_xt* self, const void* in_data, tsk_size_t in_size)
{
	int cs = 0;
	const char *p = in_data;
	const char *pe = p + in_size;
	const char *eof = pe;
	
	const char *tag_start = tsk_null;

	tmedia_imageattr_set_xt* sets = tsk_null;
	tsk_size_t* sets_count = tsk_null;
	tmedia_imageattr_xyrange_xt* xyrange = tsk_null;
	tmedia_imageattr_srange_xt* srange = tsk_null;

	TSK_RAGEL_DISABLE_WARNINGS_BEGIN()
	
/* #line 72 "./src/tmedia_imageattr.c" */
static const char _tmedia_machine_imageattr_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 14, 1, 
	15, 1, 16, 1, 17, 1, 18, 1, 
	19, 1, 20, 2, 3, 0, 2, 4, 
	0, 2, 6, 11, 2, 15, 0, 2, 
	16, 13
};

static const short _tmedia_machine_imageattr_key_offsets[] = {
	0, 0, 6, 8, 10, 12, 14, 18, 
	20, 22, 24, 26, 30, 32, 33, 36, 
	39, 41, 42, 45, 49, 55, 57, 59, 
	60, 61, 64, 65, 67, 70, 73, 74, 
	76, 79, 82, 85, 86, 88, 91, 92, 
	94, 97, 100, 101, 102, 104, 105, 107, 
	108, 110, 114, 116, 117, 118, 121, 123, 
	125, 126, 130, 131, 133, 137, 141, 145, 
	147, 148, 150, 153, 154, 156, 160, 163, 
	164, 166, 170, 174, 178, 180, 182, 183, 
	185, 188, 189, 191, 194, 197, 200, 201, 
	203, 204, 206, 210, 214, 216, 217, 219, 
	223, 227, 231, 235, 237, 239, 243, 245, 
	249, 253, 257, 261, 265, 267, 269, 273, 
	277, 281, 285, 287, 289, 293, 297, 301, 
	305, 309, 311, 313, 316, 319, 322, 325, 
	328, 329, 331, 334, 337, 340, 343, 344, 
	346, 350, 352, 356, 360, 364, 368, 372, 
	374, 375, 379, 383, 387, 391, 393, 395, 
	399, 403, 407, 411, 415, 417, 419, 422, 
	425, 428, 431, 434, 435, 436, 438, 440, 
	442, 444, 446, 447, 450, 453, 455, 456, 
	459, 463, 469, 471, 473, 474, 475, 478, 
	479, 481, 484, 487, 488, 490, 493, 496, 
	499, 500, 502, 503, 505, 508, 511, 512, 
	513, 515, 516, 518, 519, 521, 525, 527, 
	528, 529, 532, 534, 536, 537, 541, 542, 
	544, 548, 552, 556, 558, 559, 561, 564, 
	565, 567, 571, 574, 575, 577, 581, 585, 
	589, 591, 593, 594, 596, 599, 600, 602, 
	605, 608, 611, 612, 614, 615, 617, 621, 
	625, 627, 628, 630, 634, 638, 642, 646, 
	648, 650, 654, 656, 660, 664, 668, 672, 
	676, 678, 680, 684, 688, 692, 696, 698, 
	700, 704, 708, 712, 716, 720, 722, 724, 
	727, 730, 733, 736, 739, 740, 742, 745, 
	748, 751, 754, 755, 757, 761, 763, 767, 
	771, 775, 779, 783, 785, 786, 790, 794, 
	798, 802, 804, 806, 810, 814, 818, 822, 
	826, 828, 830, 833, 836, 839, 842, 845, 
	846, 847, 849, 851, 853, 855, 861, 861, 
	863, 869
};

static const char _tmedia_machine_imageattr_trans_keys[] = {
	9, 32, 82, 83, 114, 115, 69, 101, 
	67, 99, 86, 118, 9, 32, 9, 32, 
	42, 91, 69, 101, 67, 99, 86, 118, 
	9, 32, 9, 32, 42, 91, 88, 120, 
	61, 91, 49, 57, 44, 48, 57, 89, 
	121, 61, 91, 49, 57, 44, 93, 48, 
	57, 80, 81, 83, 112, 113, 115, 65, 
	97, 82, 114, 61, 91, 48, 49, 57, 
	46, 49, 57, 45, 48, 57, 48, 49, 
	57, 46, 49, 57, 93, 48, 57, 93, 
	48, 57, 93, 48, 57, 93, 44, 93, 
	9, 32, 91, 46, 48, 57, 45, 48, 
	57, 45, 48, 57, 45, 46, 48, 57, 
	61, 48, 49, 46, 48, 57, 44, 93, 
	48, 57, 44, 93, 46, 48, 44, 48, 
	93, 65, 97, 82, 114, 61, 48, 91, 
	49, 57, 46, 49, 57, 44, 93, 48, 
	57, 44, 93, 48, 57, 44, 93, 48, 
	57, 44, 93, 46, 48, 57, 48, 49, 
	57, 46, 49, 57, 44, 45, 48, 57, 
	48, 49, 57, 46, 49, 57, 44, 93, 
	48, 57, 44, 93, 48, 57, 44, 93, 
	48, 57, 44, 93, 44, 93, 46, 48, 
	57, 48, 49, 57, 46, 49, 57, 93, 
	48, 57, 93, 48, 57, 93, 48, 57, 
	93, 44, 93, 46, 48, 57, 44, 45, 
	48, 57, 44, 45, 48, 57, 44, 45, 
	46, 48, 57, 44, 93, 48, 57, 44, 
	93, 48, 57, 44, 93, 48, 57, 44, 
	93, 48, 57, 44, 93, 49, 57, 44, 
	58, 48, 57, 49, 57, 44, 93, 48, 
	57, 44, 93, 48, 57, 44, 93, 48, 
	57, 44, 93, 48, 57, 44, 93, 48, 
	57, 44, 93, 44, 93, 44, 58, 48, 
	57, 44, 58, 48, 57, 44, 58, 48, 
	57, 44, 58, 48, 57, 44, 58, 49, 
	57, 58, 93, 48, 57, 58, 93, 48, 
	57, 58, 93, 48, 57, 58, 93, 48, 
	57, 58, 93, 48, 57, 58, 93, 49, 
	57, 93, 48, 57, 93, 48, 57, 93, 
	48, 57, 93, 48, 57, 93, 48, 57, 
	93, 44, 93, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	49, 57, 44, 58, 48, 57, 49, 57, 
	44, 93, 48, 57, 44, 93, 48, 57, 
	44, 93, 48, 57, 44, 93, 48, 57, 
	44, 93, 48, 57, 44, 93, 44, 44, 
	58, 48, 57, 44, 58, 48, 57, 44, 
	58, 48, 57, 44, 58, 48, 57, 44, 
	58, 49, 57, 58, 93, 48, 57, 58, 
	93, 48, 57, 58, 93, 48, 57, 58, 
	93, 48, 57, 58, 93, 48, 57, 58, 
	93, 49, 57, 93, 48, 57, 93, 48, 
	57, 93, 48, 57, 93, 48, 57, 93, 
	48, 57, 93, 44, 69, 101, 78, 110, 
	68, 100, 9, 32, 88, 120, 61, 91, 
	49, 57, 44, 48, 57, 89, 121, 61, 
	91, 49, 57, 44, 93, 48, 57, 80, 
	81, 83, 112, 113, 115, 65, 97, 82, 
	114, 61, 91, 48, 49, 57, 46, 49, 
	57, 45, 48, 57, 48, 49, 57, 46, 
	49, 57, 93, 48, 57, 93, 48, 57, 
	93, 48, 57, 93, 44, 93, 46, 48, 
	57, 45, 48, 57, 45, 48, 57, 45, 
	46, 48, 57, 61, 48, 49, 46, 48, 
	57, 44, 93, 48, 57, 44, 93, 46, 
	48, 44, 48, 93, 65, 97, 82, 114, 
	61, 48, 91, 49, 57, 46, 49, 57, 
	44, 93, 48, 57, 44, 93, 48, 57, 
	44, 93, 48, 57, 44, 93, 46, 48, 
	57, 48, 49, 57, 46, 49, 57, 44, 
	45, 48, 57, 48, 49, 57, 46, 49, 
	57, 44, 93, 48, 57, 44, 93, 48, 
	57, 44, 93, 48, 57, 44, 93, 44, 
	93, 46, 48, 57, 48, 49, 57, 46, 
	49, 57, 93, 48, 57, 93, 48, 57, 
	93, 48, 57, 93, 44, 93, 46, 48, 
	57, 44, 45, 48, 57, 44, 45, 48, 
	57, 44, 45, 46, 48, 57, 44, 93, 
	48, 57, 44, 93, 48, 57, 44, 93, 
	48, 57, 44, 93, 48, 57, 44, 93, 
	49, 57, 44, 58, 48, 57, 49, 57, 
	44, 93, 48, 57, 44, 93, 48, 57, 
	44, 93, 48, 57, 44, 93, 48, 57, 
	44, 93, 48, 57, 44, 93, 44, 93, 
	44, 58, 48, 57, 44, 58, 48, 57, 
	44, 58, 48, 57, 44, 58, 48, 57, 
	44, 58, 49, 57, 58, 93, 48, 57, 
	58, 93, 48, 57, 58, 93, 48, 57, 
	58, 93, 48, 57, 58, 93, 48, 57, 
	58, 93, 49, 57, 93, 48, 57, 93, 
	48, 57, 93, 48, 57, 93, 48, 57, 
	93, 48, 57, 93, 44, 93, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 49, 57, 44, 58, 48, 
	57, 49, 57, 44, 93, 48, 57, 44, 
	93, 48, 57, 44, 93, 48, 57, 44, 
	93, 48, 57, 44, 93, 48, 57, 44, 
	93, 44, 44, 58, 48, 57, 44, 58, 
	48, 57, 44, 58, 48, 57, 44, 58, 
	48, 57, 44, 58, 49, 57, 58, 93, 
	48, 57, 58, 93, 48, 57, 58, 93, 
	48, 57, 58, 93, 48, 57, 58, 93, 
	48, 57, 58, 93, 49, 57, 93, 48, 
	57, 93, 48, 57, 93, 48, 57, 93, 
	48, 57, 93, 48, 57, 93, 44, 69, 
	101, 78, 110, 68, 100, 9, 32, 9, 
	32, 82, 83, 114, 115, 9, 32, 9, 
	32, 82, 83, 114, 115, 9, 32, 82, 
	83, 91, 114, 115, 0
};

static const char _tmedia_machine_imageattr_single_lengths[] = {
	0, 6, 2, 2, 2, 2, 4, 2, 
	2, 2, 2, 4, 2, 1, 1, 1, 
	2, 1, 1, 2, 6, 2, 2, 1, 
	1, 1, 1, 0, 1, 1, 1, 0, 
	1, 1, 1, 1, 2, 3, 1, 0, 
	1, 1, 1, 1, 0, 1, 2, 1, 
	0, 2, 2, 1, 1, 3, 2, 2, 
	1, 2, 1, 0, 2, 2, 2, 2, 
	1, 0, 1, 1, 0, 2, 1, 1, 
	0, 2, 2, 2, 2, 2, 1, 0, 
	1, 1, 0, 1, 1, 1, 1, 2, 
	1, 0, 2, 2, 2, 1, 0, 2, 
	2, 2, 2, 2, 0, 2, 0, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 0, 2, 2, 2, 2, 
	2, 2, 0, 1, 1, 1, 1, 1, 
	1, 2, 1, 1, 1, 1, 1, 0, 
	2, 0, 2, 2, 2, 2, 2, 2, 
	1, 2, 2, 2, 2, 2, 0, 2, 
	2, 2, 2, 2, 2, 0, 1, 1, 
	1, 1, 1, 1, 1, 2, 2, 2, 
	2, 2, 1, 1, 1, 2, 1, 1, 
	2, 6, 2, 2, 1, 1, 1, 1, 
	0, 1, 1, 1, 0, 1, 1, 1, 
	1, 2, 1, 0, 1, 1, 1, 1, 
	0, 1, 2, 1, 0, 2, 2, 1, 
	1, 3, 2, 2, 1, 2, 1, 0, 
	2, 2, 2, 2, 1, 0, 1, 1, 
	0, 2, 1, 1, 0, 2, 2, 2, 
	2, 2, 1, 0, 1, 1, 0, 1, 
	1, 1, 1, 2, 1, 0, 2, 2, 
	2, 1, 0, 2, 2, 2, 2, 2, 
	0, 2, 0, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 0, 
	2, 2, 2, 2, 2, 2, 0, 1, 
	1, 1, 1, 1, 1, 2, 1, 1, 
	1, 1, 1, 0, 2, 0, 2, 2, 
	2, 2, 2, 2, 1, 2, 2, 2, 
	2, 2, 0, 2, 2, 2, 2, 2, 
	2, 0, 1, 1, 1, 1, 1, 1, 
	1, 2, 2, 2, 2, 6, 0, 2, 
	6, 7
};

static const char _tmedia_machine_imageattr_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	0, 0, 1, 1, 0, 0, 0, 0, 
	0, 1, 0, 1, 1, 1, 0, 1, 
	1, 1, 1, 0, 0, 0, 0, 1, 
	1, 1, 0, 0, 1, 0, 0, 0, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 1, 1, 1, 1, 0, 
	0, 1, 1, 0, 1, 1, 1, 0, 
	1, 1, 1, 1, 0, 0, 0, 1, 
	1, 0, 1, 1, 1, 1, 0, 0, 
	0, 1, 1, 1, 0, 0, 1, 1, 
	1, 1, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	0, 0, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	0, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 1, 0, 
	1, 1, 1, 0, 1, 1, 1, 1, 
	0, 0, 0, 1, 1, 1, 0, 0, 
	1, 0, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 1, 
	1, 1, 1, 0, 0, 1, 1, 0, 
	1, 1, 1, 0, 1, 1, 1, 1, 
	0, 0, 0, 1, 1, 0, 1, 1, 
	1, 1, 0, 0, 0, 1, 1, 1, 
	0, 0, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 0, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 1, 0, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 0, 0, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
};

static const short _tmedia_machine_imageattr_index_offsets[] = {
	0, 0, 7, 10, 13, 16, 19, 24, 
	27, 30, 33, 36, 41, 44, 46, 49, 
	52, 55, 57, 60, 64, 71, 74, 77, 
	79, 81, 84, 86, 88, 91, 94, 96, 
	98, 101, 104, 107, 109, 112, 116, 118, 
	120, 123, 126, 128, 130, 132, 134, 137, 
	139, 141, 145, 148, 150, 152, 156, 159, 
	162, 164, 168, 170, 172, 176, 180, 184, 
	187, 189, 191, 194, 196, 198, 202, 205, 
	207, 209, 213, 217, 221, 224, 227, 229, 
	231, 234, 236, 238, 241, 244, 247, 249, 
	252, 254, 256, 260, 264, 267, 269, 271, 
	275, 279, 283, 287, 290, 292, 296, 298, 
	302, 306, 310, 314, 318, 321, 324, 328, 
	332, 336, 340, 343, 345, 349, 353, 357, 
	361, 365, 368, 370, 373, 376, 379, 382, 
	385, 387, 390, 393, 396, 399, 402, 404, 
	406, 410, 412, 416, 420, 424, 428, 432, 
	435, 437, 441, 445, 449, 453, 456, 458, 
	462, 466, 470, 474, 478, 481, 483, 486, 
	489, 492, 495, 498, 500, 502, 505, 508, 
	511, 514, 517, 519, 522, 525, 528, 530, 
	533, 537, 544, 547, 550, 552, 554, 557, 
	559, 561, 564, 567, 569, 571, 574, 577, 
	580, 582, 585, 587, 589, 592, 595, 597, 
	599, 601, 603, 606, 608, 610, 614, 617, 
	619, 621, 625, 628, 631, 633, 637, 639, 
	641, 645, 649, 653, 656, 658, 660, 663, 
	665, 667, 671, 674, 676, 678, 682, 686, 
	690, 693, 696, 698, 700, 703, 705, 707, 
	710, 713, 716, 718, 721, 723, 725, 729, 
	733, 736, 738, 740, 744, 748, 752, 756, 
	759, 761, 765, 767, 771, 775, 779, 783, 
	787, 790, 793, 797, 801, 805, 809, 812, 
	814, 818, 822, 826, 830, 834, 837, 839, 
	842, 845, 848, 851, 854, 856, 859, 862, 
	865, 868, 871, 873, 875, 879, 881, 885, 
	889, 893, 897, 901, 904, 906, 910, 914, 
	918, 922, 925, 927, 931, 935, 939, 943, 
	947, 950, 952, 955, 958, 961, 964, 967, 
	969, 971, 974, 977, 980, 983, 990, 991, 
	994, 1001
};

static const short _tmedia_machine_imageattr_trans_targs[] = {
	1, 1, 2, 321, 2, 321, 0, 3, 
	3, 0, 4, 4, 0, 5, 5, 0, 
	6, 6, 0, 6, 6, 325, 169, 0, 
	8, 8, 0, 9, 9, 0, 10, 10, 
	0, 11, 11, 0, 11, 11, 326, 12, 
	0, 13, 13, 0, 14, 0, 135, 15, 
	0, 16, 130, 0, 17, 17, 0, 18, 
	0, 100, 19, 0, 20, 327, 95, 0, 
	21, 45, 54, 21, 45, 54, 0, 22, 
	22, 0, 23, 23, 0, 24, 0, 25, 
	0, 26, 43, 0, 27, 0, 28, 0, 
	29, 40, 0, 30, 38, 0, 31, 0, 
	32, 0, 36, 33, 0, 36, 34, 0, 
	36, 35, 0, 36, 0, 20, 327, 0, 
	37, 37, 12, 0, 39, 0, 32, 0, 
	29, 41, 0, 29, 42, 0, 29, 0, 
	44, 0, 28, 0, 46, 0, 47, 51, 
	0, 48, 0, 49, 0, 20, 327, 50, 
	0, 20, 327, 0, 52, 0, 53, 0, 
	20, 50, 327, 0, 55, 55, 0, 56, 
	56, 0, 57, 0, 58, 66, 64, 0, 
	59, 0, 60, 0, 20, 327, 61, 0, 
	20, 327, 62, 0, 20, 327, 63, 0, 
	20, 327, 0, 65, 0, 60, 0, 67, 
	93, 0, 68, 0, 69, 0, 70, 80, 
	90, 0, 71, 78, 0, 72, 0, 73, 
	0, 70, 77, 74, 0, 70, 77, 75, 
	0, 70, 77, 76, 0, 70, 77, 0, 
	20, 327, 0, 79, 0, 73, 0, 81, 
	88, 0, 82, 0, 83, 0, 87, 84, 
	0, 87, 85, 0, 87, 86, 0, 87, 
	0, 20, 327, 0, 89, 0, 83, 0, 
	70, 80, 91, 0, 70, 80, 92, 0, 
	70, 80, 0, 94, 0, 69, 0, 20, 
	327, 96, 0, 20, 327, 97, 0, 20, 
	327, 98, 0, 20, 327, 99, 0, 20, 
	327, 0, 101, 0, 102, 115, 110, 0, 
	103, 0, 102, 109, 104, 0, 102, 109, 
	105, 0, 102, 109, 106, 0, 102, 109, 
	107, 0, 102, 109, 108, 0, 102, 109, 
	0, 20, 327, 0, 102, 115, 111, 0, 
	102, 115, 112, 0, 102, 115, 113, 0, 
	102, 115, 114, 0, 102, 115, 0, 116, 
	0, 122, 129, 117, 0, 122, 129, 118, 
	0, 122, 129, 119, 0, 122, 129, 120, 
	0, 122, 129, 121, 0, 122, 129, 0, 
	123, 0, 129, 124, 0, 129, 125, 0, 
	129, 126, 0, 129, 127, 0, 129, 128, 
	0, 129, 0, 20, 327, 0, 16, 131, 
	0, 16, 132, 0, 16, 133, 0, 16, 
	134, 0, 16, 0, 136, 0, 137, 150, 
	145, 0, 138, 0, 137, 144, 139, 0, 
	137, 144, 140, 0, 137, 144, 141, 0, 
	137, 144, 142, 0, 137, 144, 143, 0, 
	137, 144, 0, 16, 0, 137, 150, 146, 
	0, 137, 150, 147, 0, 137, 150, 148, 
	0, 137, 150, 149, 0, 137, 150, 0, 
	151, 0, 157, 164, 152, 0, 157, 164, 
	153, 0, 157, 164, 154, 0, 157, 164, 
	155, 0, 157, 164, 156, 0, 157, 164, 
	0, 158, 0, 164, 159, 0, 164, 160, 
	0, 164, 161, 0, 164, 162, 0, 164, 
	163, 0, 164, 0, 16, 0, 166, 166, 
	0, 167, 167, 0, 168, 168, 0, 11, 
	11, 0, 170, 170, 0, 171, 0, 291, 
	172, 0, 173, 286, 0, 174, 174, 0, 
	175, 0, 256, 176, 0, 177, 328, 251, 
	0, 178, 201, 210, 178, 201, 210, 0, 
	179, 179, 0, 180, 180, 0, 181, 0, 
	182, 0, 183, 199, 0, 184, 0, 185, 
	0, 186, 196, 0, 187, 194, 0, 188, 
	0, 189, 0, 193, 190, 0, 193, 191, 
	0, 193, 192, 0, 193, 0, 177, 328, 
	0, 195, 0, 189, 0, 186, 197, 0, 
	186, 198, 0, 186, 0, 200, 0, 185, 
	0, 202, 0, 203, 207, 0, 204, 0, 
	205, 0, 177, 328, 206, 0, 177, 328, 
	0, 208, 0, 209, 0, 177, 206, 328, 
	0, 211, 211, 0, 212, 212, 0, 213, 
	0, 214, 222, 220, 0, 215, 0, 216, 
	0, 177, 328, 217, 0, 177, 328, 218, 
	0, 177, 328, 219, 0, 177, 328, 0, 
	221, 0, 216, 0, 223, 249, 0, 224, 
	0, 225, 0, 226, 236, 246, 0, 227, 
	234, 0, 228, 0, 229, 0, 226, 233, 
	230, 0, 226, 233, 231, 0, 226, 233, 
	232, 0, 226, 233, 0, 177, 328, 0, 
	235, 0, 229, 0, 237, 244, 0, 238, 
	0, 239, 0, 243, 240, 0, 243, 241, 
	0, 243, 242, 0, 243, 0, 177, 328, 
	0, 245, 0, 239, 0, 226, 236, 247, 
	0, 226, 236, 248, 0, 226, 236, 0, 
	250, 0, 225, 0, 177, 328, 252, 0, 
	177, 328, 253, 0, 177, 328, 254, 0, 
	177, 328, 255, 0, 177, 328, 0, 257, 
	0, 258, 271, 266, 0, 259, 0, 258, 
	265, 260, 0, 258, 265, 261, 0, 258, 
	265, 262, 0, 258, 265, 263, 0, 258, 
	265, 264, 0, 258, 265, 0, 177, 328, 
	0, 258, 271, 267, 0, 258, 271, 268, 
	0, 258, 271, 269, 0, 258, 271, 270, 
	0, 258, 271, 0, 272, 0, 278, 285, 
	273, 0, 278, 285, 274, 0, 278, 285, 
	275, 0, 278, 285, 276, 0, 278, 285, 
	277, 0, 278, 285, 0, 279, 0, 285, 
	280, 0, 285, 281, 0, 285, 282, 0, 
	285, 283, 0, 285, 284, 0, 285, 0, 
	177, 328, 0, 173, 287, 0, 173, 288, 
	0, 173, 289, 0, 173, 290, 0, 173, 
	0, 292, 0, 293, 306, 301, 0, 294, 
	0, 293, 300, 295, 0, 293, 300, 296, 
	0, 293, 300, 297, 0, 293, 300, 298, 
	0, 293, 300, 299, 0, 293, 300, 0, 
	173, 0, 293, 306, 302, 0, 293, 306, 
	303, 0, 293, 306, 304, 0, 293, 306, 
	305, 0, 293, 306, 0, 307, 0, 313, 
	320, 308, 0, 313, 320, 309, 0, 313, 
	320, 310, 0, 313, 320, 311, 0, 313, 
	320, 312, 0, 313, 320, 0, 314, 0, 
	320, 315, 0, 320, 316, 0, 320, 317, 
	0, 320, 318, 0, 320, 319, 0, 320, 
	0, 173, 0, 322, 322, 0, 323, 323, 
	0, 324, 324, 0, 6, 6, 0, 325, 
	325, 7, 165, 7, 165, 0, 0, 37, 
	37, 0, 329, 329, 7, 165, 7, 165, 
	0, 329, 329, 7, 165, 169, 7, 165, 
	0, 0
};

static const char _tmedia_machine_imageattr_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	5, 5, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 7, 43, 
	0, 49, 0, 0, 0, 0, 0, 0, 
	0, 9, 46, 0, 49, 49, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 1, 0, 0, 0, 0, 0, 
	39, 0, 0, 1, 1, 0, 0, 0, 
	0, 0, 41, 0, 0, 41, 0, 0, 
	41, 0, 0, 41, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	39, 0, 0, 39, 0, 0, 39, 0, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	0, 0, 0, 0, 0, 25, 25, 0, 
	0, 25, 25, 0, 0, 0, 0, 0, 
	25, 0, 25, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 52, 31, 52, 0, 
	0, 0, 0, 0, 55, 55, 0, 0, 
	55, 55, 0, 0, 55, 55, 0, 0, 
	55, 55, 0, 0, 0, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 33, 35, 
	0, 0, 1, 1, 0, 0, 0, 0, 
	0, 33, 33, 0, 0, 33, 33, 0, 
	0, 33, 33, 0, 0, 33, 33, 0, 
	27, 27, 0, 0, 0, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 37, 0, 
	0, 37, 0, 0, 37, 0, 0, 37, 
	0, 29, 29, 0, 0, 0, 0, 0, 
	33, 35, 0, 0, 33, 35, 0, 0, 
	33, 35, 0, 0, 0, 0, 0, 49, 
	49, 0, 0, 49, 49, 0, 0, 49, 
	49, 0, 0, 49, 49, 0, 0, 49, 
	49, 0, 1, 0, 23, 17, 0, 0, 
	1, 0, 23, 23, 0, 0, 23, 23, 
	0, 0, 23, 23, 0, 0, 23, 23, 
	0, 0, 23, 23, 0, 0, 23, 23, 
	0, 13, 13, 0, 23, 17, 0, 0, 
	23, 17, 0, 0, 23, 17, 0, 0, 
	23, 17, 0, 0, 23, 17, 0, 1, 
	0, 19, 21, 0, 0, 19, 21, 0, 
	0, 19, 21, 0, 0, 19, 21, 0, 
	0, 19, 21, 0, 0, 19, 21, 0, 
	1, 0, 21, 0, 0, 21, 0, 0, 
	21, 0, 0, 21, 0, 0, 21, 0, 
	0, 21, 0, 15, 15, 0, 49, 0, 
	0, 49, 0, 0, 49, 0, 0, 49, 
	0, 0, 49, 0, 1, 0, 23, 17, 
	0, 0, 1, 0, 23, 23, 0, 0, 
	23, 23, 0, 0, 23, 23, 0, 0, 
	23, 23, 0, 0, 23, 23, 0, 0, 
	23, 23, 0, 13, 0, 23, 17, 0, 
	0, 23, 17, 0, 0, 23, 17, 0, 
	0, 23, 17, 0, 0, 23, 17, 0, 
	1, 0, 19, 21, 0, 0, 19, 21, 
	0, 0, 19, 21, 0, 0, 19, 21, 
	0, 0, 19, 21, 0, 0, 19, 21, 
	0, 1, 0, 21, 0, 0, 21, 0, 
	0, 21, 0, 0, 21, 0, 0, 21, 
	0, 0, 21, 0, 15, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 0, 0, 0, 0, 0, 0, 7, 
	43, 0, 49, 0, 0, 0, 0, 0, 
	0, 0, 9, 46, 0, 49, 49, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 0, 0, 0, 0, 
	0, 39, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 41, 0, 0, 41, 0, 
	0, 41, 0, 0, 41, 0, 0, 0, 
	0, 0, 0, 0, 0, 39, 0, 0, 
	39, 0, 0, 39, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 0, 0, 0, 
	0, 0, 25, 25, 0, 0, 25, 25, 
	0, 0, 0, 0, 0, 25, 0, 25, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 52, 31, 52, 0, 0, 0, 0, 
	0, 55, 55, 0, 0, 55, 55, 0, 
	0, 55, 55, 0, 0, 55, 55, 0, 
	0, 0, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 33, 35, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 33, 33, 
	0, 0, 33, 33, 0, 0, 33, 33, 
	0, 0, 33, 33, 0, 27, 27, 0, 
	0, 0, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 37, 0, 0, 37, 0, 
	0, 37, 0, 0, 37, 0, 29, 29, 
	0, 0, 0, 0, 0, 33, 35, 0, 
	0, 33, 35, 0, 0, 33, 35, 0, 
	0, 0, 0, 0, 49, 49, 0, 0, 
	49, 49, 0, 0, 49, 49, 0, 0, 
	49, 49, 0, 0, 49, 49, 0, 1, 
	0, 23, 17, 0, 0, 1, 0, 23, 
	23, 0, 0, 23, 23, 0, 0, 23, 
	23, 0, 0, 23, 23, 0, 0, 23, 
	23, 0, 0, 23, 23, 0, 13, 13, 
	0, 23, 17, 0, 0, 23, 17, 0, 
	0, 23, 17, 0, 0, 23, 17, 0, 
	0, 23, 17, 0, 1, 0, 19, 21, 
	0, 0, 19, 21, 0, 0, 19, 21, 
	0, 0, 19, 21, 0, 0, 19, 21, 
	0, 0, 19, 21, 0, 1, 0, 21, 
	0, 0, 21, 0, 0, 21, 0, 0, 
	21, 0, 0, 21, 0, 0, 21, 0, 
	15, 15, 0, 49, 0, 0, 49, 0, 
	0, 49, 0, 0, 49, 0, 0, 49, 
	0, 1, 0, 23, 17, 0, 0, 1, 
	0, 23, 23, 0, 0, 23, 23, 0, 
	0, 23, 23, 0, 0, 23, 23, 0, 
	0, 23, 23, 0, 0, 23, 23, 0, 
	13, 0, 23, 17, 0, 0, 23, 17, 
	0, 0, 23, 17, 0, 0, 23, 17, 
	0, 0, 23, 17, 0, 1, 0, 19, 
	21, 0, 0, 19, 21, 0, 0, 19, 
	21, 0, 0, 19, 21, 0, 0, 19, 
	21, 0, 0, 19, 21, 0, 1, 0, 
	21, 0, 0, 21, 0, 0, 21, 0, 
	0, 21, 0, 0, 21, 0, 0, 21, 
	0, 15, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 11, 
	11, 0, 11, 11, 11, 11, 11, 11, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
};

static const char _tmedia_machine_imageattr_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 11, 
	11, 0
};

static const int tmedia_machine_imageattr_start = 1;
static const int tmedia_machine_imageattr_first_final = 325;
static const int tmedia_machine_imageattr_error = 0;

static const int tmedia_machine_imageattr_en_main = 1;


/* #line 168 "./ragel/tmedia_imageattr.rl" */
	(void)(eof);
	(void)(tmedia_machine_imageattr_first_final);
	(void)(tmedia_machine_imageattr_error);
	(void)(tmedia_machine_imageattr_en_main);
	
/* #line 695 "./src/tmedia_imageattr.c" */
	{
	cs = tmedia_machine_imageattr_start;
	}

/* #line 173 "./ragel/tmedia_imageattr.rl" */
	tmedia_imageattr_reset(self);
	
/* #line 703 "./src/tmedia_imageattr.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tmedia_machine_imageattr_trans_keys + _tmedia_machine_imageattr_key_offsets[cs];
	_trans = _tmedia_machine_imageattr_index_offsets[cs];

	_klen = _tmedia_machine_imageattr_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tmedia_machine_imageattr_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _tmedia_machine_imageattr_trans_targs[_trans];

	if ( _tmedia_machine_imageattr_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tmedia_machine_imageattr_actions + _tmedia_machine_imageattr_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 40 "./ragel/tmedia_imageattr.rl" */
	{
		tag_start = p;
	}
	break;
	case 1:
/* #line 44 "./ragel/tmedia_imageattr.rl" */
	{
		sets = &self->send.sets[0];
		sets_count = &self->send.count;
		*sets_count = 0;
	}
	break;
	case 2:
/* #line 50 "./ragel/tmedia_imageattr.rl" */
	{
		sets = &self->recv.sets[0];
		sets_count = &self->recv.count;
		*sets_count = 0;
	}
	break;
	case 3:
/* #line 56 "./ragel/tmedia_imageattr.rl" */
	{
		xyrange = (*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) ? &sets[*sets_count].xrange : tsk_null;
	}
	break;
	case 4:
/* #line 59 "./ragel/tmedia_imageattr.rl" */
	{
		xyrange = (*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) ? &sets[*sets_count].yrange : tsk_null;
	}
	break;
	case 5:
/* #line 62 "./ragel/tmedia_imageattr.rl" */
	{
		if(*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) (*sets_count)++;
	}
	break;
	case 6:
/* #line 65 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange) xyrange->is_range = 0;
	}
	break;
	case 7:
/* #line 68 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange) xyrange->is_range = 1;
	}
	break;
	case 8:
/* #line 71 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange)xyrange->range.start = atoi(tag_start);
	}
	break;
	case 9:
/* #line 74 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange)xyrange->range.step = atoi(tag_start);
	}
	break;
	case 10:
/* #line 77 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange)xyrange->range.end = atoi(tag_start);
	}
	break;
	case 11:
/* #line 80 "./ragel/tmedia_imageattr.rl" */
	{
		if(xyrange && xyrange->array.count < TMEDIA_imageattr_ARRAY_MAX_SIZE){
			xyrange->array.values[xyrange->array.count++] = atoi(tag_start);
		}
	}
	break;
	case 12:
/* #line 85 "./ragel/tmedia_imageattr.rl" */
	{
		if(*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE){
			sets[*sets_count].qvalue = atof(tag_start);
		}
	}
	break;
	case 13:
/* #line 91 "./ragel/tmedia_imageattr.rl" */
	{
		if(srange) srange->is_range = 0;
	}
	break;
	case 14:
/* #line 94 "./ragel/tmedia_imageattr.rl" */
	{
		if(srange) srange->is_range = 1;
	}
	break;
	case 15:
/* #line 97 "./ragel/tmedia_imageattr.rl" */
	{
		srange = (*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) ? &sets[*sets_count].srange : tsk_null;
	}
	break;
	case 16:
/* #line 100 "./ragel/tmedia_imageattr.rl" */
	{
		if(srange && srange->array.count < TMEDIA_imageattr_ARRAY_MAX_SIZE){
			srange->array.values[srange->array.count++] = atof(tag_start);
		}
	}
	break;
	case 17:
/* #line 105 "./ragel/tmedia_imageattr.rl" */
	{
		if(srange) srange->range.start = atof(tag_start);
	}
	break;
	case 18:
/* #line 108 "./ragel/tmedia_imageattr.rl" */
	{
		if(srange) srange->range.end = atof(tag_start);
	}
	break;
	case 19:
/* #line 112 "./ragel/tmedia_imageattr.rl" */
	{
		if(*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) sets[*sets_count].prange.start = atof(tag_start);
	}
	break;
	case 20:
/* #line 115 "./ragel/tmedia_imageattr.rl" */
	{
		if(*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) sets[*sets_count].prange.end = atof(tag_start), sets[*sets_count].prange.is_present = 1;
	}
	break;
/* #line 912 "./src/tmedia_imageattr.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _tmedia_machine_imageattr_actions + _tmedia_machine_imageattr_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 5:
/* #line 62 "./ragel/tmedia_imageattr.rl" */
	{
		if(*sets_count < TMEDIA_imageattr_ARRAY_MAX_SIZE) (*sets_count)++;
	}
	break;
/* #line 934 "./src/tmedia_imageattr.c" */
		}
	}
	}

	_out: {}
	}

/* #line 175 "./ragel/tmedia_imageattr.rl" */
	TSK_RAGEL_DISABLE_WARNINGS_END()

	if( cs < 
/* #line 946 "./src/tmedia_imageattr.c" */
325
/* #line 177 "./ragel/tmedia_imageattr.rl" */
 ){
		TSK_DEBUG_ERROR("Parsing failed to parse image-attr=%s", (char*)in_data);
		return -1;
	}
	
	return 0;
}