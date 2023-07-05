from scihook import register

@register("Gmds.Gridbuilder.Build2d.Before")
def log(ctx):
    print(dir(ctx))
    print(f"""
        AXNb={ctx.AXNb}, AXStep={ctx.AXStep},
        AYNb={ctx.AYNb}, AYStep={ctx.AYStep}
    """)
    breakpoint()

@register("Gmds.Gridbuilder.Build3d.Before")
def log(ctx):
    print(dir(ctx))
    print(f"""
        AXNb={ctx.AXNb}, AXStep={ctx.AXStep},
        AYNb={ctx.AYNb}, AYStep={ctx.AYStep},
        AZNb={ctx.AZNb}, AZStep={ctx.AZStep}
    """)
    breakpoint()