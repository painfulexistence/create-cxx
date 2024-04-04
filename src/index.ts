import fs from "fs";
import path from "path";
import { program } from "commander";
import chalk from "chalk";
import spawn from "cross-spawn";

program
    .argument("[project-name]", "CXX project name")
    .option("-t, --template <template-name>", "CXX project template", "minimalist");
program.parse();

const defaultProjectName = "my-cxx-project";
const cwd = process.cwd();
const projectName = program.args[0] || defaultProjectName;
const { template } = program.opts();

async function run() {
    // TODO: Use Inquirer to prompt users

    // Create project directory
    const projectDir = path.join(cwd, projectName);
    fs.mkdirSync(projectDir, { recursive: true });

    // Copy the chosen template
    const templateDir = path.resolve(__dirname, "..", `template-${template}`);
    fs.cpSync(templateDir, projectDir, { recursive: true });

    // Rename dotfiles
    const dotfiles = [
        "gitignore",
        "gitmodules",
        "editorconfig",
        "clang-format"
    ];
    dotfiles.map((filename) => {
        const [oldPath, newPath] = [
            path.join(projectDir, filename),
            path.join(projectDir, "." + filename)
        ];
        if (fs.existsSync(oldPath)) {
            fs.renameSync(oldPath, newPath);
        }
    })

    // Closing message
    console.log(chalk.green("Done! ") + " Now run: \n");
    console.log(`cd ${projectName}`);
    console.log("git init");
    console.log("git submodule add https://github.com/microsoft/vcpkg.git && ./vcpkg/bootstrap-vcpkg.sh")
    console.log("cmake -S . -B build");
    console.log();

    //spawn.sync("cd", [projectName], { stdio: "inherit" });
    //spawn.sync("git", ["init"], { stdio: "inherit" });
    //spawn.sync("cmake", ["-S .", "-B build"], { stdio: "inherit" });
}

run().catch((e) => {
    console.log(e)
})