import { defineBuildConfig } from "unbuild";
import nodeResolver from "@rollup/plugin-node-resolve";

export default defineBuildConfig({
    entries: ["src/index"],
    rollup: {
        inlineDependencies: true
    },
    hooks: {
        // FIXME: no effect
        "rollup:options"(ctx, options) {
            options.plugins = [
                options.plugins,
                nodeResolver({
                    exportConditions: ["node"]
                })
            ];
        }
    }
});
