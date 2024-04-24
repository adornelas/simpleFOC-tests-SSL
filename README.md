# simpleFOC-tests-SSL
Tests on FOC library for BLDC motors to be used on the robots of the SSL category at the UnBall team


References:

Main library:
    https://docs.simplefoc.com/

    Monitoring:
        https://docs.simplefoc.com/monitoring

    Commander interface:
        https://docs.simplefoc.com/commander_interface
        https://docs.simplefoc.com/studio
    
    Torque control:
        https://docs.simplefoc.com/torque_control

Motor:
    https://shop.iflight.com/gimbal-motors-cat44/ipower-motor-gm4108h-120t-gimbal-motor-with-as5048a-encoder-pro243

Motor encoder magnetic sensor:
    https://br.mouser.com/datasheet/2/588/AS5048_DS000298_4_00-2324531.pdf

Driver:
    https://www.aliexpress.us/item/3256805324882671.html?spm=a2g0o.store_pc_allItems_or_groupList.0.0.5ca92d15b7Iz9a&pdp_npi=4%40dis%21BRL%21R%24%20159%2C68%21R%24%20107%2C56%21%21%2130.74%2120.71%21%40216661c117096429890006834ebee1%2112000033361166879%21sh%21BR%210%21&gatewayAdapt=glo2usa4itemAdapt

    Lib ref:
        https://github.com/makerbase-motor/MKS-ESP32FOC/tree/master

    Shield version:
        https://www.aliexpress.us/item/3256804875947998.html?pdp_npi=4%40dis%21BRL%21R%24%20133%2C03%21R%24%2096%2C08%21%21%2125.61%2118.50%21%40216661c117096429890006834ebee1%2112000033145077507%21sh%21BR%210%21&spm=a2g0o.store_pc_allItems_or_groupList.new_all_items_2007473458239.1005005062262750&gatewayAdapt=glo2usa4itemAdapt

        Lib ref:
            https://github.com/makerbase-motor/MKS-DUALFOC/tree/main

    Chip:
        Three-phase independent half-bridge driver chip:
        https://www-egmicro-com.translate.goog/chip-centers/55/EG2133/?_x_tr_sl=zh-CN&_x_tr_tl=en&_x_tr_hl=en&_x_tr_pto=sc



Unused:
Triple 1/2-H Bridge Driver:
    https://www.ti.com/lit/ds/symlink/drv8313.pdf?ts=1704921368092

Three-phase motor driver:   
    L6234

Optical incremental encoder:
    https://br.mouser.com/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D


Other option for drivers:
    https://www.ti.com/motor-drivers/brushless-dc-bldc-drivers/overview.html
    https://www.ti.com/video/series/c2000-mcus-motor-control.html

Tutorials:

ESP:
    https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/mcpwm.html#application-examples
    https://www.makerhero.com/blog/uso-de-interrupcoes-externas-com-esp32/
    https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/intr_alloc.html

BLDC Motor:
    https://www.youtube.com/watch?v=InzXA7mWBWE

Paper "Robô Holonômico Didático de Baixo Custo":
    https://www.sba.org.br/cba2022/wp-content/uploads/artigos_cba2022/paper_776.pdf

ESP-IDF with PlatformIO:
    https://docs.espressif.com/projects/esp-idf/en/stable/esp32/third-party-tools/platformio.html