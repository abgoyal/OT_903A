

#include "drmP.h"
#include "nouveau_drv.h"
#include "nouveau_hw.h"

static int
nv50_gpio_location(struct dcb_gpio_entry *gpio, uint32_t *reg, uint32_t *shift)
{
	const uint32_t nv50_gpio_reg[4] = { 0xe104, 0xe108, 0xe280, 0xe284 };

	if (gpio->line >= 32)
		return -EINVAL;

	*reg = nv50_gpio_reg[gpio->line >> 3];
	*shift = (gpio->line & 7) << 2;
	return 0;
}

int
nv50_gpio_get(struct drm_device *dev, enum dcb_gpio_tag tag)
{
	struct dcb_gpio_entry *gpio;
	uint32_t r, s, v;

	gpio = nouveau_bios_gpio_entry(dev, tag);
	if (!gpio)
		return -ENOENT;

	if (nv50_gpio_location(gpio, &r, &s))
		return -EINVAL;

	v = nv_rd32(dev, r) >> (s + 2);
	return ((v & 1) == (gpio->state[1] & 1));
}

int
nv50_gpio_set(struct drm_device *dev, enum dcb_gpio_tag tag, int state)
{
	struct dcb_gpio_entry *gpio;
	uint32_t r, s, v;

	gpio = nouveau_bios_gpio_entry(dev, tag);
	if (!gpio)
		return -ENOENT;

	if (nv50_gpio_location(gpio, &r, &s))
		return -EINVAL;

	v  = nv_rd32(dev, r) & ~(0x3 << s);
	v |= (gpio->state[state] ^ 2) << s;
	nv_wr32(dev, r, v);
	return 0;
}
