module core_top (
    input           aclk            ,
    input           aresetn         ,
    input    [ 7:0] intrpt          ,
    //AXI interface
    //read reqest
    output   [ 3:0] axi_arid            ,
    output   [31:0] axi_araddr          ,
    output   [ 7:0] axi_arlen           ,
    output   [ 2:0] axi_arsize          ,
    output   [ 1:0] axi_arburst         ,
    output   [ 1:0] axi_arlock          ,
    output   [ 3:0] axi_arcache         ,
    output   [ 2:0] axi_arprot          ,
    output          axi_arvalid         ,
    input           axi_arready         ,
    //read back
    input    [ 3:0] axi_rid             ,
    input    [31:0] axi_rdata           ,
    input    [ 1:0] axi_rresp           ,
    input           axi_rlast           ,
    input           axi_rvalid          ,
    output          axi_rready          ,
    //write request
    output   [ 3:0] axi_awid            ,
    output   [31:0] axi_awaddr          ,
    output   [ 7:0] axi_awlen           ,
    output   [ 2:0] axi_awsize          ,
    output   [ 1:0] axi_awburst         ,
    output   [ 1:0] axi_awlock          ,
    output   [ 3:0] axi_awcache         ,
    output   [ 2:0] axi_awprot          ,
    output          axi_awvalid         ,
    input           axi_awready         ,
    //write data
    output   [ 3:0] axi_wid             ,
    output   [31:0] axi_wdata           ,
    output   [ 3:0] axi_wstrb           ,
    output          axi_wlast           ,
    output          axi_wvalid          ,
    input           axi_wready          ,
    //write back
    input    [ 3:0] axi_bid             ,
    input    [ 1:0] axi_bresp           ,
    input           axi_bvalid          ,
    output          axi_bready          
);
    reg reset;
    always @(posedge aclk) begin
        reset <= ~aresetn;
    end

    iFuCore core(
        .clock(aclk)                       ,
        .reset(reset)                      ,
        .io_ext_int(intrpt)                ,
        .io_axi3_ar_ready(axi_arready)     ,
        .io_axi3_ar_valid(axi_arvalid)     ,
        .io_axi3_ar_bits_id(axi_arid)      ,
        .io_axi3_ar_bits_addr(axi_araddr)  ,
        .io_axi3_ar_bits_len(axi_arlen)    ,
        .io_axi3_ar_bits_size(axi_arsize)  ,
        .io_axi3_ar_bits_burst(axi_arburst),
        .io_axi3_ar_bits_lock(axi_arlock)  ,
        .io_axi3_ar_bits_cache(axi_arcache),
        .io_axi3_ar_bits_prot(axi_arprot)  ,
        .io_axi3_r_ready(axi_rready)       ,
        .io_axi3_r_valid(axi_rvalid)       ,
        .io_axi3_r_bits_id(axi_rid)        ,
        .io_axi3_r_bits_resp(axi_rresp)    ,
        .io_axi3_r_bits_data(axi_rdata)    ,
        .io_axi3_r_bits_last(axi_rlast)    ,
        .io_axi3_aw_ready(axi_awready)     ,
        .io_axi3_aw_valid(axi_awvalid)     ,
        .io_axi3_aw_bits_id(axi_awid)      ,
        .io_axi3_aw_bits_addr(axi_awaddr)  ,
        .io_axi3_aw_bits_len(axi_awlen)    ,
        .io_axi3_aw_bits_size(axi_awsize)  ,
        .io_axi3_aw_bits_burst(axi_awburst),
        .io_axi3_aw_bits_lock(axi_awlock)  ,
        .io_axi3_aw_bits_cache(axi_awcache),
        .io_axi3_aw_bits_prot(axi_awprot)  ,
        .io_axi3_w_ready(axi_wready)       ,
        .io_axi3_w_valid(axi_wvalid)       ,
        .io_axi3_w_bits_id(axi_wid)        ,
        .io_axi3_w_bits_data(axi_wdata)    ,
        .io_axi3_w_bits_last(axi_wlast)    ,
        .io_axi3_w_bits_strb(axi_wstrb)    ,
        .io_axi3_b_ready(axi_bready)       ,
        .io_axi3_b_valid(axi_bvalid)       ,
        .io_axi3_b_bits_id(axi_bid)        ,
        .io_axi3_b_bits_resp(axi_bresp)
    );

endmodule
