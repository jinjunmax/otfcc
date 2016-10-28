#ifndef CARYLL_INCLUDE_TABLE_POST_H
#define CARYLL_INCLUDE_TABLE_POST_H

#include "table-common.h"

typedef struct {
	// PostScript information
	f16dot16 version;
	f16dot16 italicAngle;
	int16_t underlinePosition;
	int16_t underlineThickness;
	uint32_t isFixedPitch;
	uint32_t minMemType42;
	uint32_t maxMemType42;
	uint32_t minMemType1;
	uint32_t maxMemType1;
	otfcc_GlyphOrder *post_name_map;
} table_post;

table_post *otfcc_newPost();
void otfcc_deletePost(MOVE table_post *table);
table_post *otfcc_readPost(const otfcc_Packet packet, const otfcc_Options *options);
void otfcc_dumpPost(const table_post *table, json_value *root, const otfcc_Options *options);
table_post *otfcc_parsePost(const json_value *root, const otfcc_Options *options);
caryll_Buffer *otfcc_buildPost(const table_post *post, otfcc_GlyphOrder *glyphorder, const otfcc_Options *options);

#endif
