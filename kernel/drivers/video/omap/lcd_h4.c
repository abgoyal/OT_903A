

#include <linux/module.h>
#include <linux/platform_device.h>

#include "omapfb.h"

static int h4_panel_init(struct lcd_panel *panel, struct omapfb_device *fbdev)
{
	return 0;
}

static void h4_panel_cleanup(struct lcd_panel *panel)
{
}

static int h4_panel_enable(struct lcd_panel *panel)
{
	return 0;
}

static void h4_panel_disable(struct lcd_panel *panel)
{
}

static unsigned long h4_panel_get_caps(struct lcd_panel *panel)
{
	return 0;
}

static struct lcd_panel h4_panel = {
	.name		= "h4",
	.config		= OMAP_LCDC_PANEL_TFT,

	.bpp		= 16,
	.data_lines	= 16,
	.x_res		= 240,
	.y_res		= 320,
	.pixel_clock	= 6250,
	.hsw		= 15,
	.hfp		= 15,
	.hbp		= 60,
	.vsw		= 1,
	.vfp		= 1,
	.vbp		= 1,

	.init		= h4_panel_init,
	.cleanup	= h4_panel_cleanup,
	.enable		= h4_panel_enable,
	.disable	= h4_panel_disable,
	.get_caps	= h4_panel_get_caps,
};

static int h4_panel_probe(struct platform_device *pdev)
{
	omapfb_register_panel(&h4_panel);
	return 0;
}

static int h4_panel_remove(struct platform_device *pdev)
{
	return 0;
}

static int h4_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
	return 0;
}

static int h4_panel_resume(struct platform_device *pdev)
{
	return 0;
}

static struct platform_driver h4_panel_driver = {
	.probe		= h4_panel_probe,
	.remove		= h4_panel_remove,
	.suspend	= h4_panel_suspend,
	.resume		= h4_panel_resume,
	.driver		= {
		.name	= "lcd_h4",
		.owner	= THIS_MODULE,
	},
};

static int __init h4_panel_drv_init(void)
{
	return platform_driver_register(&h4_panel_driver);
}

static void __exit h4_panel_drv_cleanup(void)
{
	platform_driver_unregister(&h4_panel_driver);
}

module_init(h4_panel_drv_init);
module_exit(h4_panel_drv_cleanup);

