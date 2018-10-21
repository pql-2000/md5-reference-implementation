#include <map>
#include <cassert>
#include <iostream>

#include "md5.h"

/*
    Assertions generated with: (zsh)

    ```
    for i in `cat /usr/share/dict/cracklib-small | shuf | sed -e "s/'//g" | head -n100`; do echo -n "{\"$i\", "; echo -n ' "'; echo -n $i | md5sum; done | sed -e "s/  -/\"},/g"
    ```
*/

void tests_assertions(void)
{
    static const std::map<std::string, std::string> assertions
    {
        {"have",  "b42dad5453b2128a32f6612b13ea5d9f"},
        {"linotype",  "ceb714da473ff329e66e3447bf39c698"},
        {"bits",  "cc411e6c13670e52124629b8ac83f7d0"},
        {"distributions",  "67c9924929e6e71642d037d6fefe4a68"},
        {"young",  "f6182f0359f72aae12fb90d305ccf9eb"},
        {"gambol",  "7cce80fb6a1d8895ddfdbfaabba49ed4"},
        {"suppress",  "674408fa67da8075268336c018ec6fc1"},
        {"sauerkraut",  "52381cef39ef6cf8b58cf1f710f05270"},
        {"gsxr750",  "ec1ffa08791e0ae7811f924ff86f1600"},
        {"luminous",  "3b34aae43a0c2f0a58d9fb6faa984bab"},
        {"doitnow",  "66e5dcdf55aa868b3bfdce7845978535"},
        {"evaded",  "4b636015da21a66943b43217559e0131"},
        {"committing",  "724ba0730054fa08f5ce69caa4361dd7"},
        {"telethon",  "9c998372cc089401eded28f3d50e3d83"},
        {"narcissus",  "2edd9e1242a8c7e54701689a5dbf6bad"},
        {"coziness",  "1aa05cfe064cae2ca7648efe5133cce6"},
        {"because",  "cc70865f1ecd933ec055851deb5bd69a"},
        {"mitigative",  "3b8314b159f6e756209d26b21cf93f92"},
        {"sequel",  "66124aaa9b39896c92d058e985281e72"},
        {"midnight",  "1506aeeb8c3a699b1e3c87db03156428"},
        {"dynamited",  "7c081b90fbe1cead93ccc91d8a7c1262"},
        {"vanes",  "5fb8f7656e91d02703ca8389529afb83"},
        {"adjusts",  "cba8462cf982e1a02ff3ee229fdb4468"},
        {"harry",  "3b87c97d15e8eb11e51aa25e9a5770e9"},
        {"crusty",  "2c7c461c7fb173557c8c56478c21ec29"},
        {"partly",  "d05332da9294920b4cc9f31595b58e7f"},
        {"slow",  "4fe9dfe784a2be25dd8aec3b403c3654"},
        {"quartile",  "ea694530c3e4967afe81b0e0ef67d54e"},
        {"speechlessness",  "86cec50d48d4f74079bc5b41a10d49b4"},
        {"percussion",  "bc0170ec03f46929a82db213582a0bbe"},
        {"centenary",  "ff62f69fd61cd51db7c2761d89c62d1f"},
        {"upturns",  "c6d1aaa162998e126d3d4bd191f9a23d"},
        {"moorish",  "7f328536fad334de99af56e40a379603"},
        {"grantor",  "9ac0fd27b4f974c996fe1b4a1be97c3f"},
        {"fahey",  "f7d2242829b7191398d8026a158313c8"},
        {"chemisorb",  "fe763169bec57a97aae602ac7bf8bffe"},
        {"leer",  "3f60eb7939d4fdcb9244c0999b175f09"},
        {"kirchner",  "b33e01101cf162b27b2bca000bc0a16d"},
        {"collocation",  "e7d1889b24c5095eba0bd08e47d454dc"},
        {"depress",  "ff1bcdbe49f5804d5df4c2268a42d3d1"},
        {"waft",  "e384d87d5de535612145b8e6f5e38076"},
        {"amort",  "aa2bd19b0d5d103cd31b022e45fa7d41"},
        {"strolling",  "6eadcf66e8c789b90450090d36dc3b12"},
        {"effectors",  "599cd2b7c932d44cd628dc40d0cb9b47"},
        {"booster",  "449a6bfbd6a81186eba0c3b996662b49"},
        {"stub",  "e8f65fd8d973f9985dc7ea3cf1614ae1"},
        {"proscribe",  "0a20f93a8da57b664df1a55bc9e13326"},
        {"formate",  "8dc7ffb0ac0bf9510c441cfe802c8253"},
        {"taxpaying",  "a49580ec8b28086fa97ef6c3786515b1"},
        {"coagulable",  "11800cfc8592b5bea4513139a7f03174"},
        {"adverse",  "8abdad3ba6bcf4a7125fa5e6f029ae69"},
        {"dictionarys",  "5af878227534762d6edd5fca315b886f"},
        {"simplifications",  "57d224397c23c116ca7a07a890e716b8"},
        {"puritan",  "cd914ed57dc2d4157a7e1d43d7853778"},
        {"annulled",  "6487853b1acaba95e5982ede7b1d3227"},
        {"infamous",  "efe1fadc9a0ca29a1f376cdd3c83e298"},
        {"scientists",  "0d40887127bee8f7731f5c4f95eb5331"},
        {"paulson",  "fe5963abdee2744878a3470b3ddbea73"},
        {"splinter",  "1f74df58d1c0f7b55b5caa01e6c7f806"},
        {"devilman",  "e2f4b11ba4591d2a84e8462623b45d60"},
        {"canoes",  "8f0c946fa197dffeebcab2213f7393cd"},
        {"campaigner",  "2537d33515ab01e3f4de8a9c21eba48a"},
        {"intimating",  "2f4f3a7128cb202392f6ce849d7a49ac"},
        {"rube",  "6b872687df9aba1933ac59abdab6302f"},
        {"seller",  "64c9ac2bb5fe46c3ac32844bb97be6bc"},
        {"maximums",  "32a47a075026654ec2cc11e7eb54223e"},
        {"mickey",  "4d5257e5acc7fcac2f5dcd66c4e78f9a"},
        {"underlying",  "4ab57483724829010c32e288b605d5e5"},
        {"gould",  "16b65bd37aa7f2eb751ff12755d49730"},
        {"alexandra",  "9db3c8f773c85206e661d7538de50fe7"},
        {"enveloper",  "6ff4d3fb60214892c9634ec143443bc6"},
        {"overload",  "1cf9f8be06cdce86bfde06213124c08b"},
        {"isentropic",  "e9bef3d7f0bb29fb53c7ae00d5ee6745"},
        {"reputable",  "175eb4b69d4ff04e56f81927059a636f"},
        {"cortland",  "39959bb750e3a2f32429a487a9862397"},
        {"bearings",  "6fc2bdbafc4589d65f9b49dfc00e88fb"},
        {"thank",  "f5ab96926a6a561aab7ecb4ba7c915d4"},
        {"scranton",  "7eaa20d9293ce488d920c703e9006af9"},
        {"candidly",  "c7c432e687cdbb698582502416bf76ad"},
        {"hug",  "af231c77af76002cdaec813c29a6db09"},
        {"depositors",  "03d5181bcf7e81a6c409574a409a4995"},
        {"sigmachi",  "c2a19a20002c4b99964c14f23f99981a"},
        {"expeditious",  "fb1880bd907dedbf8a7c628f7c380c05"},
        {"arrogated",  "3c73e632a45fdedec5dbc24d2a15594f"},
        {"beauties",  "11d9d4907d53028875120807aa296b12"},
        {"enforcement",  "42f349ce49f76cbbaeec781f7c4c6bd4"},
        {"apatite",  "158626882b06fcd06e77bf328d8f2194"},
        {"smoldered",  "cb6a40a965d805f37e0c720fc4cd54a0"},
        {"masks",  "ce38fdcaab276279ceda3f9c29a0d153"},
        {"travertine",  "48daa0b0242422dfe63b26c9f0abca62"},
        {"transmit",  "f477de506a932b4c64020556d2d4b40b"},
        {"olympic",  "133564794a1bfbfad19be33f1b1e341c"},
        {"wolff",  "7158513bcdad9fbdf2409e8ef89b878a"},
        {"qwertyui",  "22d7fe8c185003c98f97e5d6ced420c7"},
        {"ceases",  "9e7268ca8e53a2f185b86a7d30cf9afb"},
        {"worldwide",  "663c92cbb27d188f32533fc2ec4c1652"},
        {"mcdermott",  "7bdb4d5721d0e4edb43f54f7f65bcdf1"},
        {"inventions",  "ab4e67b11a87f6acc34c0e52973230c6"},
        {"ullman",  "e0e3baf6a07496f9d1a1486ee9412100"},
        {"watercourse",  "f806d529f7dbcf24f96b94961b81bccb"}
    };
    MD5 m;
    for(const auto kv : assertions)
    {
        MD5 m;
        m.update(kv.first);
        assert(m.hexdigest() == kv.second);
        m.clear();
        std::cout << "Passed assertion '" << kv.first << " == " << kv.second << "'" << std::endl;
        
    }


}