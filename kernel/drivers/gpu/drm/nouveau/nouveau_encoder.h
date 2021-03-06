

#ifndef __NOUVEAU_ENCODER_H__
#define __NOUVEAU_ENCODER_H__

#include "drm_encoder_slave.h"
#include "nouveau_drv.h"

#define NV_DPMS_CLEARED 0x80

struct nouveau_encoder {
	struct drm_encoder_slave base;

	struct dcb_entry *dcb;
	int or;

	struct drm_display_mode mode;
	int last_dpms;

	struct nv04_output_reg restore;

	void (*disconnect)(struct nouveau_encoder *encoder);

	union {
		struct {
			int mc_unknown;
			uint32_t unk0;
			uint32_t unk1;
			int dpcd_version;
			int link_nr;
			int link_bw;
		} dp;
	};
};

static inline struct nouveau_encoder *nouveau_encoder(struct drm_encoder *enc)
{
	struct drm_encoder_slave *slave = to_encoder_slave(enc);

	return container_of(slave, struct nouveau_encoder, base);
}

static inline struct drm_encoder *to_drm_encoder(struct nouveau_encoder *enc)
{
	return &enc->base.base;
}

struct nouveau_connector *
nouveau_encoder_connector_get(struct nouveau_encoder *encoder);
int nv50_sor_create(struct drm_device *dev, struct dcb_entry *entry);
int nv50_dac_create(struct drm_device *dev, struct dcb_entry *entry);

struct bit_displayport_encoder_table {
	uint32_t match;
	uint8_t  record_nr;
	uint8_t  unknown;
	uint16_t script0;
	uint16_t script1;
	uint16_t unknown_table;
} __attribute__ ((packed));

struct bit_displayport_encoder_table_entry {
	uint8_t vs_level;
	uint8_t pre_level;
	uint8_t reg0;
	uint8_t reg1;
	uint8_t reg2;
} __attribute__ ((packed));

#endif /* __NOUVEAU_ENCODER_H__ */
